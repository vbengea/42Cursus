/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:38:21 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/03 19:50:02 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

void	*routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (true)
	{
		//if (philo->id % 2 == 0)
			//ft_sleep(philo);
		pthread_mutex_lock(&philo->data->stop_mutex);
		if (philo->data->stop_simulation)
		{	pthread_mutex_unlock(&philo->data->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->stop_mutex);
		if (!philo->data->stop_simulation)
			ft_eat(philo);
		if (!philo->data->stop_simulation)
			ft_sleep(philo);
		if (!philo->data->stop_simulation)
			ft_think(philo);
	}
	return (NULL);
}


// void	*routine(void *arg)
// {
// 	t_philo *philo = (t_philo *)arg;

// 	while (true)
// 	{
// 		pthread_mutex_lock(&philo->data->stop_mutex);
// 		if (philo->data->stop_simulation)
// 		{	pthread_mutex_unlock(&philo->data->stop_mutex);
// 			break ;
// 		}
// 		pthread_mutex_unlock(&philo->data->stop_mutex);
// 		pthread_mutex_lock(&philo->data->stop_mutex);
// 		if (!philo->data->stop_simulation)
// 			ft_eat(philo);
// 		pthread_mutex_unlock(&philo->data->stop_mutex);
// 		pthread_mutex_lock(&philo->data->stop_mutex);
// 		if (!philo->data->stop_simulation)
// 			ft_sleep(philo);
// 		pthread_mutex_unlock(&philo->data->stop_mutex);
// 		pthread_mutex_lock(&philo->data->stop_mutex);
// 		if (!philo->data->stop_simulation)
// 			ft_think(philo);
// 		pthread_mutex_unlock(&philo->data->stop_mutex);
// 	}
// 	return (NULL);
// }