/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:53:51 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/01 12:46:18 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philo [philosophers] [time to die] [time to eat]");
		printf(" [time to sleep] [(optional) number of times to eat]\n");
		return (0);
	}
	if (valid_input(argv))
		init_program(&data, argc, argv);
	free_all(&data);
	return (0);
}
