/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:16:14 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/15 18:53:56 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#include "philosophers.h"

void *print_create(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	printf("Philosopher %d sucessfully created.\n", philo->id);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		init_data(argv);
		print_data();
	}
	else
		printf("Wrong number of arguments. Try again.\n");
	return (0);
}
