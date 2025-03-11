/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:28:51 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/05 13:38:10 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	enable_writing(t_philo *self)
{
	pthread_mutex_unlock(&self->values->write_lock);
}

void	disable_writing(t_philo *self)
{
	pthread_mutex_lock(&self->values->write_lock);
}

int	philo_is_dead(t_philo *self)
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

void	*philo_routine(void *arg)
{
	t_philo	*self;

	self = arg;
	while (1)
	{
		eat(self);
		if (philo_has_to_stop(self))
			break ;
		take_a_sleep(self);
		if (philo_has_to_stop(self))
			break ;
		think(self);
		if (philo_has_to_stop(self))
			break ;
	}
	return (NULL);
}
