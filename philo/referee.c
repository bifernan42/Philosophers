/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   referee.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:29:29 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/05 15:13:17 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulate_philo_death(t_philo *self)
{
	pthread_mutex_lock(&self->values->write_lock);
	pthread_mutex_lock(&self->values->dead_lock);
	self->values->dead_flag = 1;
	printf("%ld %ld died\n", ft_timestamp() - \
	self->values->start_time, self->id);
	pthread_mutex_unlock(&self->values->dead_lock);
	pthread_mutex_unlock(&self->values->write_lock);
}

int	philo_death_check(t_philo *self)
{
	pthread_mutex_lock(&self->eat_lock);
	if ((ft_timestamp() - self->last_meal_time) > self->values->time_to_die)
	{
		simulate_philo_death(self);
		pthread_mutex_unlock(&self->eat_lock);
		return (1);
	}
	pthread_mutex_unlock(&self->eat_lock);
	return (0);
}

int	print_end_of_simulation(t_values *self)
{
	pthread_mutex_lock(&self->dead_lock);
	self->dead_flag = 1;
	pthread_mutex_unlock(&self->dead_lock);
	pthread_mutex_lock(&self->write_lock);
	printf("%ld simulation ended\n", ft_timestamp() - self->start_time);
	return (1);
}

void	check_taken_meals(t_values *self, long index, int *stop)
{
	pthread_mutex_lock(&self->philo_array[index].eat_lock);
	if (self->philo_array[index].m_c < self->meals_total)
		*stop = 1;
	pthread_mutex_unlock(&self->philo_array[index].eat_lock);
}

void	*referee_routine(void *arg)
{
	int			stop;
	long		i;
	t_values	*self;

	self = (t_values *)arg;
	while (1)
	{
		stop = 0;
		i = 0;
		while (i < self->philo_total)
		{
			if (philo_death_check(&self->philo_array[i]))
				break ;
			check_taken_meals(self, i, &stop);
			if (self->dead_flag)
				break ;
			i++;
		}
		if (self->dead_flag || (stop == 0 && print_end_of_simulation(self)))
			break ;
		usleep(100);
	}
	return (NULL);
}
