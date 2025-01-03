/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:04:23 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/03 18:06:32 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

struct	s_data;
typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	size_t			meals_count;
	bool			is_full;
	size_t			last_time_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	status_lock;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	size_t			n_philos;
	size_t			time_to_eat;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_think;
	size_t			n_times_to_eat;
	size_t			meals_completed;
	size_t			start_time;
	size_t			timestamp;
	bool			stop_simulation;
	pthread_mutex_t	meals;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_t		monitor;
}	t_data;

/* Validate input */
long	ft_atol(const char *str);
bool	valid_input(char **argv);

/* Init */
int		init_data(t_data *data, int argc, char **argv);
int		init_philos(t_data *data);
int		init_threads(t_data *data);
int		init_forks(t_data *data);
// Initl all
int		init_program(t_data *data, int argc, char **argv);

/* Join threads */
int		join_threads(t_data *data);

/* Time */
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);

/* Routine */
void	*routine(void *arg);

/* Monitor */
void	*monitor_routine(void *arg);

/* Actions */
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_think(t_philo *philo);

/* Clean */
void	free_all(t_data *data);
void	destroy_mutex(t_data *data);

#endif
