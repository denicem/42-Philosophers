/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:16:14 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/15 22:13:45 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *print_create(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	// printf("Philosopher %d sucessfully created.\n", philo->id);
	philo_sleep(philo->id);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	// (void) argc;
	// (void) argv;
	if (argc == 5 || argc == 6)
	{
		init_data(argv);
		print_data();
		for (int i = 0; i < data()->count_philo; i++)
			pthread_join(data()->philos[i]->p_id, NULL);
	}
	else
		printf("Wrong number of arguments. Try again.\n");
	return (0);
}
