/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:53:21 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/02 20:04:10 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data->n_philos = (size_t)ft_atol(argv[1]);
	data->time_to_die = (size_t)ft_atol(argv[2]);
	data->time_to_eat = (size_t)ft_atol(argv[3]);
	data->time_to_sleep = (size_t)ft_atol(argv[4]);
	if (argc == 6)
		data->n_times_to_eat = ft_atol(argv[5]);
	
	data->start_time = get_current_time();
	data->stop_simulation = false;
	return (0);
}
