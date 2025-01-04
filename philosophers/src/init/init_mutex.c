/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:27:51 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/04 20:34:35 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

int	init_mutex(t_data *data)
{
	size_t	i;

	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->meals, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (1);
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&data->philos[i].status_lock, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
