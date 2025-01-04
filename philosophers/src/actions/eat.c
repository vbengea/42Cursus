/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:04:17 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/04 20:09:59 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

static void	lock_forks_in_order(t_philo *philo, pthread_mutex_t **first, pthread_mutex_t **second)
{
	if (philo->id % 2 == 0)
	{
		*first = philo->l_fork;
		*second = philo->r_fork;
	}
	else
	{
		*first = philo->r_fork;
		*second = philo->l_fork;
	}
}


static int	try_lock_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	pthread_mutex_lock(&philo->data->stop_mutex);
	if (philo->data->stop_simulation)
	{
		pthread_mutex_unlock(&philo->data->stop_mutex);
		pthread_mutex_unlock(fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (0);
}

static void	print_fork_taken(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%zu %d has taken a fork\n",
		get_current_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

static void	eat_action(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%zu %d is eating\n",
		get_current_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print);

	pthread_mutex_lock(&philo->status_lock);
	philo->last_time_meal = get_current_time();
	philo->meals_count++;
	pthread_mutex_unlock(&philo->status_lock);

	ft_usleep(philo->data->time_to_eat);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;

	lock_forks_in_order(philo, &fork1, &fork2);
	if (try_lock_fork(philo, fork1))
		return ;
	print_fork_taken(philo);
	if (try_lock_fork(philo, fork2))
	{
		pthread_mutex_unlock(fork1);
		return ;
	}
	print_fork_taken(philo);
	eat_action(philo);
	pthread_mutex_unlock(fork2);
	pthread_mutex_unlock(fork1);
}


// void	ft_eat(t_philo *philo)
// {
// 	size_t	timestamp;

// 	pthread_mutex_lock(philo->l_fork);
// 	pthread_mutex_lock(philo->r_fork);
// 	pthread_mutex_lock(&philo->status_lock);
// 	philo->last_time_meal = get_current_time();
// 	philo->meals_count++;
// 	pthread_mutex_unlock(&philo->status_lock);
// 	timestamp = get_current_time() - philo->data->start_time;
// 	pthread_mutex_lock(&philo->data->print);
// 	printf("%zu %d has taken a fork\n", timestamp, philo->id);
// 	printf("%zu %d has taken a fork\n", timestamp, philo->id);
// 	printf("%zu %d is eating\n", timestamp, philo->id);
// 	pthread_mutex_unlock(&philo->data->print);
// 	ft_usleep(philo->data->time_to_eat);
// 	pthread_mutex_unlock(philo->l_fork);
// 	pthread_mutex_unlock(philo->r_fork);
// }