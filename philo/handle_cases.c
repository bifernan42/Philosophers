/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:28:00 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/16 14:35:48 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulate_one(t_values *self)
{
	self->start_time = ft_timestamp();
	printf("%ld 1 has taken a fork\n", ft_timestamp() - self->start_time);
	usleep(self->time_to_die * 1000);
	printf("%ld 1 died\n", ft_timestamp() - self->start_time);
}

void	simulate_many(t_values *self, long thread_number)
{
	long	i;

	i = 0;
	self->start_time = ft_timestamp();
	while (i < thread_number)
	{
		self->philo_array[i].last_meal_time = ft_timestamp();
		if (pthread_create(&self->threads[i], NULL, philo_routine, \
		&self->philo_array[i]))
			exit_and_clean_with_error(STDERR_FILENO, self, \
			"error : failed to create a thread\n");
		i++;
		usleep(100);
	}
	if (pthread_create(&self->threads[i], NULL, referee_routine, (void *)self))
		exit_and_clean_with_error(STDERR_FILENO, self, \
		"error : failed to create a thread\n");
	i = 0;
	while (i <= thread_number)
		pthread_join(self->threads[i++], NULL);
}
