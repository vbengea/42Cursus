/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:46:03 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/04 18:54:30 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

static	void	check_is_full(t_data *data, size_t i)
{
	pthread_mutex_lock(&data->philos[i].status_lock);
	if (data->philos[i].meals_count == data->n_times_to_eat)
	{
		if (!data->philos[i].is_full)
		{
			data->philos[i].is_full = true;
			pthread_mutex_lock(&data->meals);
			data->meals_completed++;
			if (data->meals_completed == data->n_philos)
			{
				pthread_mutex_lock(&data->stop_mutex);
				data->stop_simulation = true;
				pthread_mutex_unlock(&data->stop_mutex);
			}
			pthread_mutex_unlock(&data->meals);
		}
	}
	pthread_mutex_unlock(&data->philos[i].status_lock);
}

static	void	check_dead(t_data *data, size_t i)
{
	size_t	timestamp;

	timestamp = get_current_time() - data->start_time;
	pthread_mutex_lock(&data->philos[i].status_lock);
	if ((get_current_time() - data->philos[i].last_time_meal) \
		> data->time_to_die)
	{
		pthread_mutex_lock(&data->stop_mutex);
		data->stop_simulation = true;
		printf("%zu %d died\n", timestamp, data->philos[i].id);
		pthread_mutex_unlock(&data->stop_mutex);
		pthread_mutex_unlock(&data->philos[i].status_lock);
		return ;
	}
	pthread_mutex_unlock(&data->philos[i].status_lock);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	size_t	i;

	data = (t_data *)arg;
	while (!data->stop_simulation)
	{
		i = 0;
		while (i < data->n_philos)
		{
			if (data->stop_simulation)
				return (NULL);
			check_dead(data, i);
			if (data->stop_simulation)
				return (NULL);
			check_is_full(data, i);
			if (data->stop_simulation)
				return (NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
