/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:53:21 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/03 19:01:05 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

int	init_data(t_data *data, int argc, char **argv)
{
	size_t	check_data;

	data->n_philos = (size_t)ft_atol(argv[1]);
	data->time_to_die = (size_t)ft_atol(argv[2]);
	data->time_to_eat = (size_t)ft_atol(argv[3]);
	data->time_to_sleep = (size_t)ft_atol(argv[4]);
	if (argc == 6)
		data->n_times_to_eat = ft_atol(argv[5]);
	else
		data->n_times_to_eat = -1;
	data->start_time = get_current_time();
	data->timestamp = get_current_time();
	data->stop_simulation = false;
	data->meals_completed = 0;
	
	check_data = data->time_to_die - (data->time_to_eat + data->time_to_sleep);
	if (check_data > 10)
		data->time_to_think = check_data - 10;
	else
		data->time_to_think = 0;
	return (0);
}
