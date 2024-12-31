/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:04:23 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/31 12:49:17 by vbcvali          ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	size_t			meals_count;
	bool			is_full;
	size_t			last_time_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_data
{
	size_t			n_philos;
	size_t			time_to_eat;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			n_times_to_eat;
	size_t			start;
	size_t			end;
	pthread_mutex_t	*forks;
	t_philo			*philos;
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

/* Time */
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);

/* Routine */
void	*routine(void *arg);

#endif
