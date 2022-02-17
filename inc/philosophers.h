/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:14:59 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/17 17:29:00 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				next;
	pthread_t		p_id;
	pthread_mutex_t	fork;
}	t_philo;


typedef struct s_data
{
	int				count_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_meal;
	t_philo			**philos;

	time_t			start;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	sleep_lock;
}	t_data;

t_data	*data();
void	init_data(char **argv);
void	print_data();

void	init_philos();
void	print_act(int id, char *msg);
void	*philo_activity(void *arg);
void	philo_sleep(int id);
void	philo_eat(int id, int next_id);
void	philo_thinks(int id);

time_t	timestamp(void);
void	ft_usleep(time_t val);

#	endif