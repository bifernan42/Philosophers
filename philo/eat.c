/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:27:36 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/16 14:35:20 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down_forks(t_philo *self)
{
	pthread_mutex_unlock(self->left_fork);
	pthread_mutex_unlock(self->right_fork);
}

void	start_eating(t_philo *self)
{
	pthread_mutex_lock(&self->eat_lock);
}

void	finish_eating(t_philo *self)
{
	pthread_mutex_unlock(&self->eat_lock);
}

void	eat(t_philo *self)
{
	if (!take_left_fork(self))
		return ;
	if (!take_right_fork(self))
		return ;
	enable_writing(self);
	pthread_mutex_lock(&self->eat_lock);
	self->m_c++;
	self->last_meal_time = ft_timestamp();
	pthread_mutex_unlock(&self->eat_lock);
	take_some_time(self, self->values->time_to_eat);
	put_down_forks(self);
}
