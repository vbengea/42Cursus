/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:04:17 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/02 17:37:20 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	printf("Timestamp %d has taken a fork\n", philo->id);
	printf("Timestamp %d has taken a fork\n", philo->id);
	printf("Timestamp %d is eating\n", philo->id);

	pthread_mutex_lock(&philo->status_lock);
	philo->last_time_meal = get_current_time() - philo->last_time_meal;
	philo->meals_count++;
	pthread_mutex_unlock(&philo->status_lock);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
