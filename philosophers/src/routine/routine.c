/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:38:21 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/31 13:09:10 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

void	*routine(void *arg)
{
	t_data *data = (t_data *)arg;

	size_t i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(data->philos[i].l_fork);
		pthread_mutex_lock(data->philos[i].r_fork);
		printf("Philo id: %d\n", data->philos[i].id);
		pthread_mutex_unlock(data->philos[i].l_fork);
		pthread_mutex_unlock(data->philos[i].r_fork);
		i++;
	}
	return (NULL);
}
