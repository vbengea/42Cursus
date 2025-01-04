/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:08:23 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/04 18:47:24 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

int	init_program(t_data *data, int argc, char **argv)
{
	if (init_data(data, argc, argv) != 0)
		return (1);
	if (init_philos(data) != 0)
		return (1);
	if (init_forks(data) != 0)
		return (1);

	//Temporal initialization of mutexes here
	pthread_mutex_init(&data->stop_mutex, NULL);
	pthread_mutex_init(&data->meals, NULL);
	pthread_mutex_init(&data->print, NULL);

	size_t i = 0;
	while (i < data->n_philos)
		pthread_mutex_init(&data->philos[i++].status_lock, NULL);
	if (init_threads(data) != 0)
		return (1);
	if (join_threads(data) != 0)
		return (1);
	return (0);
}
