/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:29:38 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/05 13:46:46 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_a_sleep(t_philo *self)
{
	disable_writing(self);
	if (!philo_is_dead(self))
		printf("%ld %ld is sleeping\n", \
		ft_timestamp() - self->values->start_time, self->id);
	enable_writing(self);
	take_some_time(self, self->values->time_to_sleep);
}
