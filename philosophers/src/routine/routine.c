/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:38:21 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/01 12:23:02 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

void	*routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	size_t i = 0;
	//while (!philo->data->stop_simulation || philo->meals_count != philo->data->n_times_to_eat)
	while (philo->meals_count != philo->data->n_times_to_eat)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		printf("%ld %d has taken a fork\n", philo->data->end, philo->id);
		printf("%ld %d has taken a fork\n", philo->data->end, philo->id);
		printf("%ld %d is eating\n", philo->data->end ,philo->id);
		philo->last_time_meal = get_current_time() - philo->last_time_meal;
		philo->meals_count++;
		philo->data->end += (get_current_time() - philo->data->start);
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);

		printf("%ld %d is sleeping\n", philo->data->end ,philo->id);
		ft_usleep(philo->data->time_to_sleep);
		i++;
	}
	return (NULL);
}
