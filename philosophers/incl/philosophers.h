/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:04:23 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/28 10:58:08 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_data
{
	__uint64_t	time_to_eat;
	__uint64_t	time_to_die;
	__uint64_t	time_to_sleep;
	__uint64_t	time_to_think;
	int			n_times_to_eat;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	bool			has_two_forks;
	bool			has_fork;
	t_data			data;
}	t_philo;

long	ft_atol(const char *str);
bool	valid_input(char **argv);

#endif
