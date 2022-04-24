/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:54:08 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/24 22:39:51 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_activity(void *arg)
{
	t_philo	*philo;

	while (data()->philos_created < data()->count_philos)
		usleep(50);
	if (!data()->start)
		data()->start = timestamp();
	philo = (t_philo *) arg;
	philo->last_meal = timestamp();
	if (philo->id % 2)
		ft_usleep(data()->time_to_eat);
	while (philo->status != dead && data()->all_alive && !check_all_full())
	{
		if (!check_philo_starving(philo) && data()->all_alive)
		{
			if (philo->status == waiting)
				philo_eats(philo);
			else if (philo->status == sleeping)
				philo_sleeps(philo);
			else if (philo->status == thinking)
				philo_thinks(philo->id);
		}
	}
	return (NULL);
}

void	print_act(int id, char *msg)
{
	pthread_mutex_lock(&data()->lock);
	if (data()->all_alive)
	{
		pthread_mutex_lock(&data()->print);
		printf("%ld\tPhilo %d %s\n", timestamp() - data()->start, id + 1, msg);
		pthread_mutex_unlock(&data()->print);
	}
	pthread_mutex_unlock(&data()->lock);
}

int	switch_status(int id, int before)
{
	if (before == waiting)
		data()->philos[id]->status = sleeping;
	else if (before == sleeping)
		data()->philos[id]->status = thinking;
	else if (before == thinking)
		data()->philos[id]->status = waiting;
	return (1);
}

int	philo_thinks(int id)
{
	if (data()->all_alive)
	{
		print_act(id, "is thinking.");
		switch_status(id, thinking);
	}
	return (1);
}
