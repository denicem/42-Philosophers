/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:16:14 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/13 20:37:56 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#include "philosophers.h"

// int count = 0;
// pthread_mutex_t mutex;

// void *routine()
// {

// 	for (int i = 0; i < 10000000; i++)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		count++;
// 		pthread_mutex_unlock(&mutex);
// 	}
// 	return (NULL);
// }

// void *roll_dice(void *arg)
// {
// 	(void) arg;
// 	int *res = malloc(sizeof(int));
// 	int val = (rand() % 6) + 1;

// 	*res = val;
// 	return ((void *) res);
// }

t_info	*info()
{
	static t_info	info;

	return (&info);
}

void init_info(char **argv)
{
	(void) argv;
	info()->count_philo = atoi(argv[1]);
	info()->time_to_die = atoi(argv[2]);
	info()->time_to_eat = atoi(argv[3]);
	info()->time_to_sleep = atoi(argv[4]);
	if (argv[5])
		info()->count_meal = atoi(argv[5]);
}

void	print_info()
{
	printf("INFO:\n");
	printf("Philosophers:\t%d\n", info()->count_philo);
	printf("Time to die:\t%d\n", info()->time_to_die);
	printf("Time to eat:\t%d\n", info()->time_to_eat);
	printf("Time to sleep:\t%d\n", info()->time_to_sleep);
	printf("Meal goals:\t%d\n", info()->count_meal);
}

int	main(int argc, char *argv[])
{
	// (void) argc;
	// (void) argv;
	// {
	// 	int i = 0;
	// 	int loop = 8;

	// 	pthread_t	thds[loop];

	// 	pthread_mutex_init(&mutex, NULL);
	// 	while (i < loop)
	// 	{
	// 		pthread_create(thds + i, NULL, &routine, NULL);
	// 		printf("Thread %d started.\n", i++);
	// 	}
	// 	i = 0;
	// 	while (i < loop)
	// 	{
	// 	pthread_join(thds[i], NULL);
	// 		printf("Thread %d finished execution. - %d\n", i++, count);
	// 	}
	// 	pthread_mutex_destroy(&mutex);
	// 	printf("%d\n", count);
	// }

	// {
	// 	int *res;
	// 	srand(time(NULL));
	// 	pthread_t	th;
	// 	pthread_create(&th, NULL, &roll_dice, NULL);
	// 	pthread_join(th, (void **) &res);
	// 	printf("You diced %d\n", *res);
	// 	free(res);
	// }

	{
		t_info	*information;
		
		information = info();
		if (argc == 5 || argc == 6)
		{
			init_info(argv);
			print_info();
		}
	}

	return (0);
}
