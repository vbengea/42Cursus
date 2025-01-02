/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:46:03 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/02 18:49:55 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

static	void	check_dead(t_data *data, size_t i)
{
	pthread_mutex_lock(&data->philos[i].status_lock);
	if ((get_current_time() - data->philos[i].last_time_meal) \
		> data->time_to_die)
	{
		//timestamp may need mutex lock. 
		//data->timestamp = get_current_time() - data->start_time;
		printf("%zu %zu has died\n", data->timestamp, data->philos[i].id);
		data->stop_simulation = true;
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
			check_dead(data, i);
			if (data->stop_simulation)
				return (NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
