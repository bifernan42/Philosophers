/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:29:47 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/05 13:47:07 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *self)
{
	disable_writing(self);
	if (!philo_is_dead(self))
		printf("%ld %ld is thinking\n", \
		ft_timestamp() - self->values->start_time, self->id);
	enable_writing(self);
	take_some_time(self, self->values->time_to_think);
}
