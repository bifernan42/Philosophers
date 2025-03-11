/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:28:10 by bifernan          #+#    #+#             */
/*   Updated: 2024/07/16 14:32:26 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_parsing_info(t_values *config)
{
	printf("number of philosophers = %ld\n", config->philo_total);
	printf("time to die = %ld\n", config->time_to_die);
	printf("time to sleep = %ld\n", config->time_to_sleep);
	printf("time to eat = %ld\n", config->time_to_eat);
	if (config->opt)
		printf("number of meals = %ld\n", config->meals_total);
}

void	start_simulation(t_values *values)
{
	if (values->philo_total == 1)
		simulate_one(values);
	else
		simulate_many(values, values->philo_total);
}

int	main(int argc, char *argv[])
{
	t_values	values;

	parser(&values, argc, argv);
	values_init(&values);
	start_simulation(&values);
	values_destroy(&values);
	return (0);
}
