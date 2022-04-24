/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:14:03 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/24 18:08:30 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	check_all_alive(void)
{
	int	i;

	i = 0;
	while (i < data()->count_philos)
	{
		if (data()->philos[i]->status == dead)
			return (false);
		i++;
	}
	return (true);
}

bool	check_philo_starving(t_philo *philo)
{
	pthread_mutex_lock(&data()->lock);
	if (timestamp() - philo->last_meal >= data()->time_to_die && data()->all_alive)
	{
		// printf("OK\n");
		// philo->status = dead;
		// print_act(philo->id, "died.");
		data()->all_alive = false;
		pthread_mutex_lock(&data()->print);
		printf("%ld\tPhilo %d died.\n", timestamp() - data()->start, philo->id + 1);
		pthread_mutex_unlock(&data()->print);
		pthread_mutex_unlock(&data()->lock);
		return (true);
	}
	pthread_mutex_unlock(&data()->lock);
	return (false);
}

bool	check_philo_is_full(t_philo *philo)
{
	if (data()->count_meals >= 0 && philo->meals >= data()->count_meals)
		return (true);
	return (false);
}

bool	check_all_full(void)
{
	int	i;

	i = 0;
	while (i < data()->count_philos)
	{
		if (!check_philo_is_full(data()->philos[i]))
			return (false);
		i++;
	}
	return (true);
}
