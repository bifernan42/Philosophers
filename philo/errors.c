/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:27:44 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/05 15:09:18 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

void	write_error(int fd, const char *msg)
{
	write(fd, msg, ft_strlen(msg));
}

void	exit_with_error(int fd, const char *msg)
{
	write(fd, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	exit_and_clean_with_error(int fd, t_values *values, const char *msg)
{
	values_destroy(values);
	exit_with_error(fd, msg);
}
