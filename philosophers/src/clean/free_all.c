/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:39:49 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/01 12:45:01 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

//static	void	free_mutex(t_data *data)
//{
//	int	i;
//
//	i = 0;
//	while (i < )
//}

void	free_all(t_data *data)
{
	//free_mutex(data);
	//free_philos(data);
	if (data->forks)
		free (data->forks);
	if (data->philos)
		free (data->philos);
}