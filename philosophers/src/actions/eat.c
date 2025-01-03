/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:04:17 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/03 19:53:58 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

// void	ft_eat(t_philo *philo)
// {
// 	size_t	timestamp;

// 	if (philo->l_fork < philo->r_fork)
// 	{
// 		pthread_mutex_lock(philo->l_fork);
// 		pthread_mutex_lock(philo->r_fork);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(philo->r_fork);
// 		pthread_mutex_lock(philo->l_fork);
// 	}

// 	timestamp = get_current_time() - philo->data->start_time;
// 	pthread_mutex_lock(&philo->data->print);
// 	printf("%zu %d has taken a fork\n", timestamp, philo->id);
// 	printf("%zu %d has taken a fork\n", timestamp, philo->id);
// 	printf("%zu %d is eating\n", timestamp, philo->id);
// 	pthread_mutex_unlock(&philo->data->print);

// 	pthread_mutex_lock(&philo->status_lock);
	
// 	philo->last_time_meal = get_current_time();
// 	philo->meals_count++;
// 	pthread_mutex_unlock(&philo->status_lock);
// 	ft_usleep(philo->data->time_to_eat);
// 	pthread_mutex_unlock(philo->l_fork);
// 	pthread_mutex_unlock(philo->r_fork);
// }


void	ft_eat(t_philo *philo)
{
	size_t	timestamp;

	// if (philo->l_fork < philo->r_fork)
	// {
	// 	pthread_mutex_lock(philo->l_fork);
	// 	pthread_mutex_lock(philo->r_fork);
	// }
	// else
	// {
	// 	pthread_mutex_lock(philo->r_fork);
	// 	pthread_mutex_lock(philo->l_fork);
	// }
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);

	pthread_mutex_lock(&philo->status_lock);
	
	philo->last_time_meal = get_current_time();
	philo->meals_count++;
	pthread_mutex_unlock(&philo->status_lock);

	timestamp = get_current_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print);
	printf("%zu %d has taken a fork\n", timestamp, philo->id);
	printf("%zu %d has taken a fork\n", timestamp, philo->id);
	printf("%zu %d is eating\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->data->print);

	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}