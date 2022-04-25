/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:51:19 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/25 21:01:39 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_free_philos(int count)
{
	while (count >= 0)
	{
		pthread_mutex_destroy(&data()->philos[count]->fork);
		free(data()->philos[count]);
		count--;
	}
}

static bool	check_valid_args(void)
{
	if (data()->count_philos < 1 || data()->time_to_die < 1
		|| data()->time_to_eat < 1 || data()->time_to_sleep < 1)
		return (false);
	if (data()->count_meals < -1 || data()->count_meals == 0)
		return (false);
	return (true);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

static bool	check_only_digit(char *str)
{
	if (*str == '+')
	{
		str++;
		if (!ft_isdigit(*str))
			return (false);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	get_input(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!check_only_digit(args[i]))
			return (error_msg("Only numeric arguments."));
		i++;
	}
	data()->count_philos = ft_atoi(args[0]);
	data()->time_to_die = ft_atoi(args[1]);
	data()->time_to_eat = ft_atoi(args[2]);
	data()->time_to_sleep = ft_atoi(args[3]);
	if (args[4])
		data()->count_meals = ft_atoi(args[4]);
	else
		data()->count_meals = -1;
	if (!check_valid_args())
		return (error_msg("Invalid arguments."));
	return (SUCCESS);
}
