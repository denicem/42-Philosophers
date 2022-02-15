/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:07:51 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/15 22:16:36 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		data()->philos[i]->next = (i + 2) % data()->count_philo;
		if (pthread_create(&data()->philos[i]->p_id, NULL, &print_create, data()->philos[i]))
			printf("Philosopher won't join. :(");
		if (pthread_mutex_init(&data()->philos[i]->fork, NULL))
			printf("Philosopher didn't get a fork. :(");
		i++;
	}
}

void	print_msg(int id, char *msg)
{
	printf("%d\t Philo %d %s\n", data()->timestamp, id, msg);
}

void	philo_sleep(int id)
{
	pthread_mutex_lock(&data()->sleep_lock);
	if (!usleep(data()->time_to_sleep * 1000))
	{
		data()->timestamp += data()->time_to_sleep;
	}
	print_msg(id, "is sleeping");
	pthread_mutex_unlock(&data()->sleep_lock);
}
