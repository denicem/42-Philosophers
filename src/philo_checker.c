/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:14:03 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/18 19:16:36 by dmontema         ###   ########.fr       */
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
