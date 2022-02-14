/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:16:14 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/14 17:05:57 by dmontema         ###   ########.fr       */
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

void *print_create(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	printf("Philosopher %d sucessfully created.\n", philo->id);
	return (NULL);
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
		if (argc == 5 || argc == 6)
		{
			init_info(argv);
			print_info();
		}
	}
	return (0);
}

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
	info()->philos = malloc(sizeof(t_philo **) * info()->count_philo);
	init_philos();
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

////////////////////////////////////////////////////////////////////////


void	init_philos()
{
	int i;
	int count_philo;

	i = 0;
	count_philo = info()->count_philo;
	while (i < count_philo)
	{
		info()->philos[i] = malloc(sizeof(t_philo *));
		info()->philos[i]->id = i;
		if (pthread_create(&info()->philos[i]->p_id, NULL, &print_create, info()->philos[i]))
			printf("Philosopher won't join. :(");
		if (pthread_mutex_init(&info()->philos[i]->fork, NULL))
			printf("Philosopher didn't get a fork. :(");
		i++;
	}
}

//////////////////////// DUMP

// t_philo	*new_philo(int th_id)
// {
// 	t_philo *new;

// 	new = (t_philo *) malloc(sizeof(t_philo *));
// 	if (!new)
// 		return (NULL);
// 	new->id = th_id;
// 	// pthread_create(&(new->philo), NULL, &print_create, NULL);
// 	// pthread_mutex_init(&(new->fork), NULL);
// 	new->next = new;
// 	return (new);
// }

// int	insert_philo(t_philo **head, t_philo *new)
// {
// 	t_philo	*tmp;
// 	int h_id;

// 	if (!new)
// 		return (0);
// 	if (!(*head))
// 	{
// 		*head = new;
// 		(*head)->next = *head;
// 		return (1);
// 	}
// 	tmp = *head;
// 	h_id = tmp->id;
// 	while (tmp->next->id != (*head)->id)
// 		tmp = tmp->next;
// 	new->next = *head;
// 	tmp->next = new;
// 	return (1);
// }

// void	print_philos(t_philo *head)
// {
// 	t_philo	*tmp;

// 	if (!head)
// 		return ;
// 	tmp = head;
// 	printf("Philosopher: %d\n", tmp->id);
// 	tmp = tmp->next;
// 	while (tmp->id != head->id)
// 	{
// 	// printf("OK\n");
// 		printf("Philosopher: %d\n", tmp->id);
// 		tmp = tmp->next;
// 	}
// }
