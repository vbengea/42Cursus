/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:29:08 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/01 12:35:15 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < (int)data->n_philos)
			pthread_mutex_destroy(&data->forks[i++]);
	}
}
