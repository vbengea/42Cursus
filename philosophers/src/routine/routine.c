/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:38:21 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/04 13:00:45 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

static	void	*one_philo(t_philo *philo)
{
	size_t	timestamp;

	while (!philo->data->stop_simulation)
	{
		timestamp = get_current_time() - philo->data->start_time;
		pthread_mutex_lock(philo->l_fork);
		printf("%zu %d has taken a fork\n", timestamp, philo->id);
		ft_usleep(philo->data->time_to_die + 1);
		pthread_mutex_unlock(philo->l_fork);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->data->n_philos == 1)
		return (one_philo(philo));
	while (true)
	{
		if (philo->data->stop_simulation)
			break ;
		if (!philo->data->stop_simulation)
			ft_eat(philo);
		if (!philo->data->stop_simulation)
			ft_sleep(philo);
		if (!philo->data->stop_simulation)
			ft_think(philo);
	}
	return (NULL);
}
