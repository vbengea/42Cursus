/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:26:18 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/30 12:33:13 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

int	init_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(data->philos[i].thread, NULL,
			(void *)&routine, (void *)data) != 0)
			return (1);
		i++;
	}
	return (0);
}