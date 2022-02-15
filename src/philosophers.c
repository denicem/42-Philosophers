/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:07:51 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/15 23:17:03 by dmontema         ###   ########.fr       */
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
		data()->philos[i]->id = i;
		data()->philos[i]->next = (i + 1) % data()->count_philo;
		if (pthread_create(&data()->philos[i]->p_id, NULL, &philo_activity, data()->philos[i]))
			printf("Philosopher won't join. :(");
		if (pthread_mutex_init(&data()->philos[i]->fork, NULL))
			printf("Philosopher didn't get a fork. :(");
		i++;
	}
}

void *philo_activity(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	// printf("Philosopher %d sucessfully created.\n", philo->id + 1);
	int i = 0;
	while (i < 5)
	{
		philo_eat(philo->id, philo->next);
		// philo_sleep(philo->id);
		i++;
	}
	
	return (NULL);
}

void	print_act(int id, char *msg)
{
	printf("%d\t Philo %d %s\n", data()->timestamp, id + 1, msg);
}

void	philo_sleep(int id)
{
	pthread_mutex_lock(&data()->sleep_lock);
	if (!usleep(data()->time_to_sleep * 1000))
		data()->timestamp += data()->time_to_sleep;
	print_act(id, "is sleeping");
	pthread_mutex_unlock(&data()->sleep_lock);
}

void	philo_eat(int id, int next_id)
{
	// printf("OK %d %d\n", id, next_id);
	if (!pthread_mutex_lock(&(data()->philos[id]->fork)))
	{
		print_act(id, "has taken a fork");
		if (!pthread_mutex_lock(&(data()->philos[next_id]->fork)))
		{
			print_act(id, "has taken a forkk");
			print_act(id, "is eating");
		}
		pthread_mutex_unlock(&(data()->philos[next_id]->fork));
		pthread_mutex_unlock(&(data()->philos[id]->fork));
	}
}
