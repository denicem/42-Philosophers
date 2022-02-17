/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:08:31 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/17 18:09:58 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

time_t	timestamp(void)
{
	struct timeval	time;
	time_t			ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000;
	ms += time.tv_usec / 1000;
	return (ms);
}

void	ft_usleep(time_t val)
{
	time_t curr;

	curr = timestamp();
	while (1)
	{
		if (val + curr <= timestamp())
			break ;
		usleep(50);
	}
}