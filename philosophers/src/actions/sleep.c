/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:08:08 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/03 18:08:44 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

void	ft_sleep(t_philo *philo)
{
	size_t	timestamp;

	timestamp = get_current_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print);
	printf("%zu %d is sleeping\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	ft_usleep(philo->data->time_to_sleep);
}
