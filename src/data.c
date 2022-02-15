/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:21:52 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/15 22:10:22 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*data()
{
	static t_data	data;

	return (&data);
}

void init_data(char **argv)
{
	data()->count_philo = atoi(argv[1]);
	data()->time_to_die = atoi(argv[2]);
	data()->time_to_eat = atoi(argv[3]);
	data()->time_to_sleep = atoi(argv[4]);
	if (argv[5])
		data()->count_meal = atoi(argv[5]);
	else
		data()->count_meal = -1;
	data()->timestamp = gettimeofday(&data()->curr_t, NULL);
	pthread_mutex_init(&data()->sleep_lock, NULL);
	data()->philos = malloc(sizeof(t_philo **) * data()->count_philo);
	init_philos();
}

void	print_data()
{
	printf("INFO:\n");
	printf("Philosophers:\t%d\n", data()->count_philo);
	printf("Time to die:\t%d\n", data()->time_to_die);
	printf("Time to eat:\t%d\n", data()->time_to_eat);
	printf("Time to sleep:\t%d\n", data()->time_to_sleep);
	if (data()->count_meal >= 0)
		printf("Meal goals:\t%d\n", data()->count_meal);
	else
		printf("Meal goals:\t%c\n", '/');
}
