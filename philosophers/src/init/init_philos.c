/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:06:31 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/29 20:15:18 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philos)
		return (1);
	i = 0;
	while (i < data->n_philos)
	{
		data->philos->id = i + 1;
		data->philos->meals_count = 0;
		data->philos->is_full = false;
		data->philos->last_time_meal = 0;
		i++;
	}
	return (0);
}