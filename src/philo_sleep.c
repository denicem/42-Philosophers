/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:40:11 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/25 00:44:50 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_sleeps(t_philo *philo)
{
	time_t	sleep_dur;

	if (data()->all_alive)
	{
		sleep_dur = timestamp() + data()->time_to_sleep;
		print_act(philo->id, "is sleeping.");
		while (timestamp() <= sleep_dur && data()->all_alive)
		{
			usleep(50);
			check_philo_starving(philo);
		}
		switch_status(philo->id, sleeping);
	}
}
