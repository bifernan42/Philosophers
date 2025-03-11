/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:29:58 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/15 17:09:42 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	values_mutex_init(t_values *values)
{
	int	i;

	if (!values)
		return ;
	i = 0;
	while (i < values->philo_total)
	{
		if (pthread_mutex_init(&values->fork_array[i++], NULL))
			exit_with_error(STDERR_FILENO, \
			"error : fork init failed\n");
	}
	if (pthread_mutex_init(&values->time_lock, NULL))
		exit_with_error(STDERR_FILENO, \
		"error : fork init failed\n");
	if (pthread_mutex_init(&values->dead_lock, NULL))
		exit_with_error(STDERR_FILENO, \
		"error : fork init failed\n");
	if (pthread_mutex_init(&values->write_lock, NULL))
		exit_with_error(STDERR_FILENO, \
		"error : fork init failed\n");
}

void	values_philos_init(t_values *values)
{
	int	i;

	if (!values)
		return ;
	i = 0;
	while (i < values->philo_total)
	{
		values->philo_array[i].id = i + 1;
		values->philo_array[i].left_fork = &values->fork_array[i];
		values->philo_array[i].right_fork = \
		&values->fork_array[(i + 1) % values->philo_total];
		values->philo_array[i].values = values;
		values->philo_array[i].thread = &values->threads[i];
		values->philo_array[i].m_c = 0;
		if (pthread_mutex_init(\
		&values->philo_array[i].eat_lock, NULL))
			exit_with_error(STDERR_FILENO, \
			"error : eating_lock init failed\n");
		i++;
	}
}

void	values_init(t_values *values)
{
	if (!values)
		return ;
	values->dead_flag = 0;
	values_mutex_init(values);
	values_philos_init(values);
}

void	values_destroy(t_values *values)
{
	int	i;

	if (!values)
		return ;
	i = 0;
	while (i < values->philo_total)
	{
		pthread_mutex_destroy(&values->fork_array[i]);
		pthread_mutex_destroy(&values->philo_array[i].eat_lock);
		i++;
	}
	pthread_mutex_destroy(&values->dead_lock);
	pthread_mutex_destroy(&values->write_lock);
	pthread_mutex_destroy(&values->time_lock);
}
