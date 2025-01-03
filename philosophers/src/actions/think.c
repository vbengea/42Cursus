/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:40:54 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/03 19:02:54 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

void	ft_think(t_philo *philo)
{
	size_t	timestamp;

	timestamp = get_current_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print);
	printf("%zu %d is thinking\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	ft_usleep(1);//philo->data->time_to_think);
}