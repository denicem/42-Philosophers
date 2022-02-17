/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:16:14 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/17 21:28:39 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	// (void) argc;
	// (void) argv;
	if (argc == 5 || argc == 6)
	{
		init_data(argv);
		// print_data();
		for (int i = 0; i < data()->count_philo; i++)
			pthread_join(data()->philos[i]->p_id, NULL);
		// printf("%ld\n", timestamp() - data()->start);
		for (int i = 0; i < data()->count_philo; i++)
			printf("MEALS for Philo %d: %d\n", i, data()->philos[i]->meals);
			// printf("LAST MEAL for Philo %d: %ld\n", i + 1, data()->philos[i]->last_meal - data()->start);
	}
	else
		printf("Wrong number of arguments. Try again.\n");
	return (0);
}
