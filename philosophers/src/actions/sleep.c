/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:08:08 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/02 13:11:14 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

void	ft_sleep(t_philo *philo)
{
	printf("Timestamp %d is sleeping\n", philo->id);
	ft_usleep(philo->data->time_to_sleep);
}
