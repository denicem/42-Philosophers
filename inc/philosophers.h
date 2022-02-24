/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:14:59 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/24 22:15:12 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

enum e_status
{
	waiting,
	sleeping,
	thinking
};

typedef struct s_philo
{
	int				id;
	int				next_id;
	pthread_t		p_id;
	pthread_mutex_t	fork;

	int				status;
	int				meals;
	time_t			last_meal;
	
}	t_philo;

typedef struct s_data
{
	int		count_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		count_meals;
	t_philo	**philos;

	int		philos_created;
	time_t	start;
	pthread_mutex_t	print;
}	t_data;

t_data	*data(void);
t_philo	*new_philo(int id);
void	init_philos(void);
void	init_data(char **args);

void	*philo_activity(void *arg);
void	print_act(int id, char *msg);
int		philo_eat(int id, int next_id);
int		philo_sleep(int id);
int		switch_status(int id, int before);

time_t	timestamp(void);
void	ft_usleep(time_t val);

#	endif