/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:08:23 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/04 20:35:07 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philosophers.h"

int	init_program(t_data *data, int argc, char **argv)
{
	if (init_data(data, argc, argv) != 0)
		return (1);
	if (init_philos(data) != 0)
		return (1);
	if (init_forks(data) != 0)
		return (1);
	if (init_mutex(data) != 0)
		return (1);
	if (init_threads(data) != 0)
		return (1);
	if (join_threads(data) != 0)
		return (1);
	return (0);
}
