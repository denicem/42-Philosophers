/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:16:14 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/02 13:35:50 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

int count = 0;
pthread_mutex_t mutex;

void *routine()
{
	pthread_mutex_lock(&mutex);
	for (int i = 0; i < 10000000; i++)
		count++;
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

void *roll_dice(void *arg)
{
	(void) arg;
	int *res = malloc(sizeof(int));
	int val = (rand() % 6) + 1;

	*res = val;
	return ((void *) res);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
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

	{
		int *res;
		srand(time(NULL));
		pthread_t	th;
		pthread_create(&th, NULL, &roll_dice, NULL);
		pthread_join(th, (void **) &res);
		printf("You diced %d\n", *res);
		free(res);
	}


	return (0);
}
