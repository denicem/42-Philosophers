/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:07:51 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/17 21:28:40 by dmontema         ###   ########.fr       */
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
		// data()->philos[i]->meals = 0;
		data()->philos[i]->last_meal = 0;
		// printf("philo %d init meals: %d\n", i,  data()->philos[i]->meals);
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
	while (i < 2)
	{
		// if (philo->id % 2)
		// 	ft_usleep(50);
		philo_eat(philo->id, philo->next);
		philo_sleep(philo->id);
		philo_thinks(philo->id);
		i++;
	}
	
	return (NULL);
}

void	print_act(int id, char *msg)
{
	pthread_mutex_lock(&data()->print_lock);
	printf("%ld\t Philo %d %s\n",timestamp() - data()->start, id + 1, msg);
	// printf("%ld\t Philo %d %s (nxt: %d)\n",timestamp() - data()->start, id + 1, msg, data()->philos[id]->next + 1);
	pthread_mutex_unlock(&data()->print_lock);
}

void	philo_sleep(int id)
{
	pthread_mutex_lock(&data()->sleep_lock);
	print_act(id, "is sleeping");
	ft_usleep(data()->time_to_sleep);
	pthread_mutex_unlock(&data()->sleep_lock);
}

void	philo_eat(int id, int next_id)
{
	// printf("OK %d %d\n", id, next_id);
	// if (id % 2)
	// 	usleep(50);
	pthread_mutex_lock(&(data()->philos[id]->fork));
	print_act(id, "has taken a fork");
	pthread_mutex_lock(&(data()->philos[next_id]->fork));
	print_act(id, "has taken a forkk");
	data()->philos[id]->meals += 1;
	data()->philos[id]->last_meal = timestamp();
	print_act(id, "is eating");
	ft_usleep(data()->time_to_eat);
	pthread_mutex_unlock(&(data()->philos[next_id]->fork));
	pthread_mutex_unlock(&(data()->philos[id]->fork));
}

void	philo_thinks(int id)
{
	print_act(id, "is thinking");
}
