/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:28:23 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/05 15:10:36 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	take_some_time(t_philo *self, const long ammount)
{
	long	total;

	total = ft_timestamp() + ammount;
	while (ft_timestamp() < total)
	{
		usleep(100);
		pthread_mutex_lock(&self->values->dead_lock);
		if (self->values->dead_flag)
		{
			pthread_mutex_unlock(&self->values->dead_lock);
			break ;
		}
		pthread_mutex_unlock(&self->values->dead_lock);
	}
}

int	philo_has_to_stop(t_philo *self)
{
	pthread_mutex_lock(&self->values->dead_lock);
	if (self->values->dead_flag)
	{
		pthread_mutex_unlock(&self->values->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&self->values->dead_lock);
	return (0);
}
