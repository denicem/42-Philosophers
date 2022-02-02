/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:16:14 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/02 11:37:10 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

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

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	int i = 0;
	int loop = 4;

	pthread_t	t1[loop];

	pthread_mutex_init(&mutex, NULL);
	while (i < loop)
	{
		pthread_create(t1 + i, NULL, &routine, NULL);
		printf("Thread %d started.\n", i++);
	}
	i = 0;
	while (i < loop)
	{
	pthread_join(t1[i], NULL);
		printf("Thread %d finished execution.\n", i++);
	}
	pthread_mutex_destroy(&mutex);
	printf("%d\n", count);

	return (0);
}
