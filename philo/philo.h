/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:11:44 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/16 14:52:32 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef MAX_PHILO
#  define MAX_PHILO 200
# endif

# ifndef MIN_PHILO
#  define MIN_PHILO 1
# endif

typedef struct s_philo				t_philo;
typedef struct s_values				t_values;

struct	s_philo
{
	t_values		*values;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	eat_lock;
	pthread_t		*thread;
	long			id;
	long			last_meal_time;
	long			m_c;
};

struct								s_values
{
	int								opt;
	long							philo_total;
	long							philo_count;
	long							time_to_die;
	long							time_to_eat;
	long							time_to_sleep;
	long							time_to_think;
	long							meals_total;
	long							start_time;
	long							dead_flag;
	pthread_mutex_t					time_lock;
	pthread_mutex_t					dead_lock;
	pthread_mutex_t					write_lock;
	pthread_mutex_t					fork_array[MAX_PHILO];
	t_philo							philo_array[MAX_PHILO];
	pthread_t						threads[MAX_PHILO + 1];
};

///////////////
// PARSING.C //
///////////////

void	parser(t_values *self, int argc, char *argv[]);
void	check_parsing_info(t_values *self);
void	get_parsing_info(t_values *self, int argc, char *argv[]);
long	ft_atoi(const char *number_string);

//////////////
// ERRORS.C //
//////////////

int		ft_strlen(const char *str);
void	write_error(int fd, const char *msg);
void	exit_with_error(int fd, const char *msg);
void	exit_and_clean_with_error(int fd, t_values *values, const char *msg);

///////////
// EAT.C //
///////////

void	put_down_forks(t_philo *self);
void	start_eating(t_philo *self);
void	finish_eating(t_philo *self);
void	eat(t_philo *self);

////////////////////
// HANDLE_CASES.C //
////////////////////

void	simulate_one(t_values *self);
void	simulate_many(t_values *self, long thread_number);

////////////
// MISC.C //
////////////

long	ft_timestamp(void);
void	take_some_time(t_philo *self, const long ammount);
int		philo_has_to_stop(t_philo *self);

/////////////
// PHILO.C //
/////////////

void	enable_writing(t_philo *self);
void	disable_writing(t_philo *self);
int		philo_is_dead(t_philo *self);
void	*philo_routine(void *arg);

////////////////////
// PHILO_CHECKS.C //
////////////////////

int		take_left_fork(t_philo *self);
void	put_down_left_fork(t_philo *self);
int		take_right_fork(t_philo *self);

///////////////
// REFEREE.C //
///////////////

void	simulate_philo_death(t_philo *self);
int		philo_death_check(t_philo *self);
int		print_end_of_simulation(t_values *self);
void	check_taken_meals(t_values *self, long index, int *stop);
void	*referee_routine(void *arg);

/////////////
// SLEEP.C //
/////////////

void	take_a_sleep(t_philo *self);

/////////////
// THINK.C //
/////////////

void	think(t_philo *self);

//////////////
// VALUES.C //
//////////////

void	values_init(t_values *values);
void	values_destroy(t_values *values);
#endif
