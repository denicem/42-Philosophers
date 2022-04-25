/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:14:59 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/25 21:07:01 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define BLACK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define WHITE	"\033[0;37m"
# define RESET	"\033[0m"

# define SUCCESS 0
# define FAIL 1

enum e_status
{
	dead = -1,
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
	bool			fork_free;

	int				status;
	int				meals;
	time_t			last_meal;
}	t_philo;

typedef struct s_data
{
	int				count_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_meals;
	t_philo			**philos;
	bool			all_alive;
	int				philos_created;
	time_t			start;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
}		t_data;

t_data	*data(void);
t_philo	*new_philo(int id);
int		init_philos(void);
int		init_data(char **args);

void	*philo_activity(void *arg);
void	print_act(int id, char *msg);
void	philo_eats(t_philo *philo);
void	philo_sleeps(t_philo *philo);
int		philo_thinks(int id);
int		switch_status(int id, int before);

bool	check_all_alive(void);
bool	check_philo_starving(t_philo *philo);
bool	check_philo_is_full(t_philo *philo);
bool	check_all_full(void);

time_t	timestamp(void);
void	ft_usleep(time_t val);

int		ft_atoi(const char *str);

int		get_input(char **args);
int		error_msg(char *str);
void	error_free_philos(int count);

void	free_philos(void);

#	endif