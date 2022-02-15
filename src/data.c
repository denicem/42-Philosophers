/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:21:52 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/15 18:55:57 by dmontema         ###   ########.fr       */
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
	printf("Meal goals:\t%d\n", data()->count_meal);
}

void	init_philos()
{
	int i;
	int count_philo;

	i = 0;
	count_philo = data()->count_philo;
	while (i < count_philo)
	{
		data()->philos[i] = malloc(sizeof(t_philo *));
		data()->philos[i]->id = i + 1;
		if (pthread_create(&data()->philos[i]->p_id, NULL, &print_create, data()->philos[i]))
			printf("Philosopher won't join. :(");
		if (pthread_mutex_init(&data()->philos[i]->fork, NULL))
			printf("Philosopher didn't get a fork. :(");
		i++;
	}
}