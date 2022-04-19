/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:54:08 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/19 20:12:09 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_activity(void *arg)
{
	t_philo	*philo;

	while (data()->philos_created < data()->count_philos)
		usleep(50);
	philo = (t_philo *) arg;
	philo->last_meal = timestamp();
	if (philo->id % 2)
		ft_usleep(data()->time_to_eat);
	while (philo->status != dead && check_all_alive() && !check_all_full())
	{
		// printf("last meal [%d]: %ld\n", philo->id + 1, timestamp() - philo->last_meal);
		if (!check_philo_starving(philo) && check_all_alive())
		{
			if (philo->status == waiting)
				philo_eat(philo->id, philo->next_id);
			if (philo->status == sleeping)
				philo_sleep(philo->id);
			if (philo->status == thinking)
				philo_think(philo->id);
		}
	}
	return (NULL);
}

void	print_act(int id, char *msg)
{
	pthread_mutex_lock(&data()->print);
	printf("%ld\tPhilo %d %s\n", timestamp() - data()->start, id + 1, msg);
	pthread_mutex_unlock(&data()->print);
}

int	philo_eat(int id, int next_id)
{
	if (check_all_alive())
	{
		pthread_mutex_lock(&data()->philos[id]->fork);
		print_act(id, "has taken a fork.");
		if (!check_all_alive())
		{
			pthread_mutex_unlock(&data()->philos[id]->fork);
			return (1);
		}
		pthread_mutex_lock(&data()->philos[next_id]->fork);
		print_act(id, "has taken a fork.");
		print_act(id, "is eating.");
		ft_usleep(data()->time_to_eat);
		switch_status(id, waiting);
		data()->philos[id]->last_meal = timestamp();
		data()->philos[id]->meals++;
		pthread_mutex_unlock(&data()->philos[next_id]->fork);
		pthread_mutex_unlock(&data()->philos[id]->fork);
	}
	return (1);
}

int	philo_sleep(int id)
{
	if (check_all_alive())
	{
		print_act(id, "is sleeping.");
		ft_usleep(data()->time_to_sleep);
		switch_status(id, sleeping);
		check_philo_starving(data()->philos[id]);
	}
	return (1);
}

int	philo_think(int id)
{
	if (check_all_alive())
	{
		print_act(id, "is thinking.");
		switch_status(id, thinking);
	}
	return (1);
}

int	switch_status(int id, int before)
{
	if (before == waiting)
		data()->philos[id]->status = sleeping;
	if (before == sleeping)
		data()->philos[id]->status = thinking;
	if (before == thinking)
		data()->philos[id]->status = waiting;
	return (1);
}
