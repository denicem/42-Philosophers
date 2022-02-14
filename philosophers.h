/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:14:59 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/14 17:01:43 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	pthread_t		p_id;
	pthread_mutex_t	fork;
}	t_philo;

void	init_philos();

typedef struct s_info
{
	int		count_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		count_meal;
	t_philo	**philos;
}	t_info;

t_info	*info();
void	init_info(char **argv);
void	print_info();

// DUMP
// t_philo	*new_philo(int th_id);
// int		insert_philo(t_philo **head, t_philo *new);
// void	print_philos(t_philo *head);