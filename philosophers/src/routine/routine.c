/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:38:21 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/02 19:51:50 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

void	*routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (true)
	{
		pthread_mutex_lock(&philo->data->stop_mutex);
		if (philo->data->stop_simulation)
		{	pthread_mutex_unlock(&philo->data->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->stop_mutex);
		ft_eat(philo);
		ft_sleep(philo);
		//ft_think(philo);
	}
	return (NULL);
}
