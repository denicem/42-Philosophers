/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:14:03 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/19 20:10:23 by dmontema         ###   ########.fr       */
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
	if (timestamp() - philo->last_meal >= data()->time_to_die)
	{
		philo->status = dead;
		print_act(philo->id, "has died.");
		return (true);
	}
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
