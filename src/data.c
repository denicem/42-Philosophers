/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:08:32 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/25 21:06:36 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_philos(void)
{
	int	i;

	i = 0;
	while (data()->philos[i])
	{
		pthread_mutex_destroy(&data()->philos[i]->fork);
		free(data()->philos[i]);
		i++;
	}
	free(data()->philos);
	pthread_mutex_destroy(&data()->print);
	pthread_mutex_destroy(&data()->lock);
}

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_philo	*new_philo(int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->next_id = (id + 1) % data()->count_philos;
	philo->status = waiting;
	philo->meals = 0;
	if (pthread_mutex_init(&philo->fork, NULL))
	{
		free (philo);
		return (NULL);
	}
	philo->fork_free = true;
	if (pthread_create(&philo->p_id, NULL, &philo_activity, (void *) philo))
	{
		pthread_mutex_destroy(&philo->fork);
		free(philo);
		return (NULL);
	}
	else
		data()->philos_created++;
	return (philo);
}

int	init_philos(void)
{
	int	i;

	i = 0;
	while (i < data()->count_philos)
	{
		data()->philos[i] = new_philo(i);
		if (!data()->philos[i])
		{
			if (i)
				error_free_philos(i - 1);
			return (FAIL);
		}
		i++;
	}
	data()->philos[i] = 0;
	return (SUCCESS);
}

int	init_data(char **args)
{
	if (get_input(args) == SUCCESS)
	{
		data()->all_alive = true;
		data()->philos = malloc(sizeof(t_philo *) * data()->count_philos + 1);
		if (!data()->philos)
			return (FAIL);
		if (pthread_mutex_init(&data()->print, NULL) == -1)
		{
			free(data()->philos);
			return (FAIL);
		}
		if (pthread_mutex_init(&data()->lock, NULL) == -1)
		{
			pthread_mutex_destroy(&data()->print);
			return (FAIL);
		}
		data()->philos_created = 0;
		data()->start = 0;
		if (init_philos() == FAIL)
			return (FAIL);
		return (SUCCESS);
	}
	return (FAIL);
}
