/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:28:39 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/16 14:37:18 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *number_string)
{
	long	rez;
	long	sign;
	long	i;

	if (!number_string)
		return (0);
	rez = 0;
	i = 0;
	sign = 1;
	while (number_string[i] == ' ' || (number_string[i] >= 9 \
	&& number_string[i] <= 13))
		i++;
	while (number_string[i] == '+' || number_string[i] == '-')
	{
		if (number_string[i] == '-')
			sign *= -1;
		i++;
	}
	while (number_string[i] >= '0' && number_string[i] <= '9')
	{
		rez = rez * 10 + (number_string[i] - '0');
		i++;
	}
	return (rez * sign);
}

void	get_parsing_info(t_values *self, int argc, char *argv[])
{
	if (argc == 5)
	{
		self->opt = 0;
		self->philo_total = ft_atoi(argv[1]);
		self->time_to_die = ft_atoi(argv[2]);
		self->time_to_eat = ft_atoi(argv[3]);
		self->time_to_sleep = ft_atoi(argv[4]);
	}
	else if (argc == 6)
	{	
		self->opt = 1;
		self->philo_total = ft_atoi(argv[1]);
		self->time_to_die = ft_atoi(argv[2]);
		self->time_to_eat = ft_atoi(argv[3]);
		self->time_to_sleep = ft_atoi(argv[4]);
		self->meals_total = ft_atoi(argv[5]);
	}
	else
		exit_with_error(STDERR_FILENO, "error : invalid number of arguments\n");
}

void	check_parsing_info(t_values *self)
{
	if (!self)
		return ;
	self->time_to_think = self->time_to_die - self->time_to_eat - \
	self->time_to_sleep;
	if (self->philo_total < (long)MIN_PHILO || \
	self->philo_total > (long)MAX_PHILO)
		exit_with_error(STDERR_FILENO, \
		"error : invalid number of philosophers\n");
	if (self->opt && (self->meals_total < 1 \
	|| self->meals_total > 2147483647))
		exit_with_error(STDERR_FILENO, \
		"error : invalid optional argument\n");
	if (self->time_to_die < 1 || self->time_to_die > 2147483647)
		exit_with_error(STDERR_FILENO, "error : invalid time to die\n");
	if (self->time_to_sleep < 1 || self->time_to_sleep > 2147483647)
		exit_with_error(STDERR_FILENO, "error : invalid time to sleep\n");
	if (self->time_to_eat < 1 || self->time_to_eat > 2147483547)
		exit_with_error(STDERR_FILENO, "error : invalid time to eat\n");
	if (self->time_to_think < 1)
		exit_with_error(STDERR_FILENO, "error : invalid time to think\n");
	if (!self->opt)
		self->meals_total = 2147483648;
}

void	parser(t_values *self, int argc, char *argv[])
{
	get_parsing_info(self, argc, argv);
	check_parsing_info(self);
}
