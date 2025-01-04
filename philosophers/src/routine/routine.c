/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:38:21 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/04 20:19:40 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

static	int	check_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_mutex);
	if (philo->data->stop_simulation)
	{
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (0);
}

static	void	*one_philo(t_philo *philo)
{
	size_t	timestamp;

	while (!philo->data->stop_simulation)
	{
		timestamp = get_current_time() - philo->data->start_time;
		pthread_mutex_lock(philo->l_fork);
		printf("%zu %d has taken a fork\n", timestamp, philo->id);
		ft_usleep(philo->data->time_to_die + 2);
		pthread_mutex_unlock(philo->l_fork);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->n_philos == 1)
		return (one_philo(philo));
	while (true)
	{
		if (check_stop(philo))
			break ;
		ft_eat(philo);
		if (check_stop(philo))
			break ;
		ft_sleep(philo);
		if (check_stop(philo))
			break ;
		ft_think(philo);
	}
	return (NULL);
}
