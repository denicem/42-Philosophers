/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:08:32 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/24 19:20:45 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		return (NULL);
	philo->fork_free = true;
	if (pthread_create(&philo->p_id, NULL, &philo_activity, (void *) philo))
		return (NULL);
	else
		data()->philos_created++;
	return (philo);
}

void	init_philos(void)
{
	int	i;

	i = 0;
	while (i < data()->count_philos)
	{
		data()->philos[i] = new_philo(i);
		if (!data()->philos[i])
			return ; // TODO: free all philos, if initializing mutex failed.
		i++;
	}
	data()->philos[i] = 0;
}

void	init_data(char **args)
{
	data()->count_philos = atoi(args[1]);
	data()->time_to_die = atoi(args[2]);
	data()->time_to_eat = atoi(args[3]);
	data()->time_to_sleep = atoi(args[4]);
	if (args[5])
		data()->count_meals = atoi(args[5]);
	else
		data()->count_meals = -1;
	data()->all_alive = true;
	data()->philos = malloc(sizeof(t_philo *) * data()->count_philos + 1);
	if (!data()->philos)
		return ; // TODO: call a error-exiting func!
	pthread_mutex_init(&data()->print, NULL);
	pthread_mutex_init(&data()->lock, NULL);
	data()->philos_created = 0;
	data()->start = 0;
	init_philos();
}
