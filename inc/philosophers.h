/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:14:59 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/15 19:00:11 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	pthread_t		p_id;
	pthread_mutex_t	fork;
}	t_philo;


typedef struct s_data
{
	int		count_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		count_meal;
	t_philo	**philos;
}	t_data;

t_data	*data();
void	init_data(char **argv);
void	print_data();
void	init_philos();

void *print_create(void *arg);

#	endif