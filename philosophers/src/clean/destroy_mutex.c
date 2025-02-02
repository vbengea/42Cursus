/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:29:08 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/04 11:55:04 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

void	destroy_mutex(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].status_lock);
		i++;
	}
	pthread_mutex_destroy(&data->stop_mutex);
	pthread_mutex_destroy(&data->meals);
	pthread_mutex_destroy(&data->print);
}
// TO DO

/* Update a flag when initializing a mutex to know when to destroy it
	There is no official way to check if a mutex has been initialized and 
	destroying an unitialized mutex can lead to undefined behavior */