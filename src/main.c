/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:16:14 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/25 21:01:23 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_msg(char *str)
{
	if (!str)
		printf("%sERROR.%s\n", RED, RESET);
	else
		printf("%sERROR:%s %s\n", RED, RESET, str);
	return (FAIL);
}



void	philo_join(void)
{
	int	i;

	i = 0;
	while (i < (data()->count_philos))
	{
		pthread_join(data()->philos[i]->p_id, NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		if (init_data(argv + 1) == SUCCESS)
			philo_join();
	}
	else
		printf("%sERROR:%s Wrong number of arguments.\n", RED, RESET);
	return (0);
}
