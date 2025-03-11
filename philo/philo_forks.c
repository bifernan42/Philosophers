/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:29:03 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/16 14:45:04 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_left_fork(t_philo *self)
{
	if (philo_is_dead(self))
		return (0);
	pthread_mutex_lock(self->left_fork);
	disable_writing(self);
	if (!philo_is_dead(self))
		printf("%ld %ld has taken a fork\n", \
		ft_timestamp() - self->values->start_time, self->id);
	enable_writing(self);
	return (1);
}

void	put_down_left_fork(t_philo *self)
{
	pthread_mutex_unlock(self->left_fork);
}

int	take_right_fork(t_philo *self)
{
	if (philo_is_dead(self))
	{
		put_down_left_fork(self);
		return (0);
	}
	pthread_mutex_lock(self->right_fork);
	disable_writing(self);
	if (!philo_is_dead(self) && ((self->values->opt && \
	self->m_c < self->values->meals_total) || !self->values->opt))
	{
		printf("%ld %ld has taken a fork\n", \
		ft_timestamp() - self->values->start_time, self->id);
		printf("%ld %ld is eating\n", \
		ft_timestamp() - self->values->start_time, self->id);
	}
	return (1);
}
