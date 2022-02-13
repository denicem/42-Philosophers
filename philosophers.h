/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:14:59 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/13 20:32:16 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	pthread_mutex_t	fork;
	struct s_philo	*next;
}	t_philo;

typedef struct s_info
{
	int	count_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	count_meal;
}	t_info;

