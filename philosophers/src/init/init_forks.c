/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:18:49 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/31 11:59:31 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

int	init_forks(t_data *data)
{
	size_t	i;
	size_t	n_philos;

	n_philos = data->n_philos;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		data->philos[i].l_fork = &data->forks[(i - 1 + n_philos) % n_philos];
		data->philos[i].r_fork = &data->forks[(i + 1) % n_philos];
		i++;
	}
	return (0);
}
