/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:53:51 by vbcvali           #+#    #+#             */
/*   Updated: 2025/01/04 13:23:30 by vbcvali          ###   ########.fr       */
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
	{
		init_program(&data, argc, argv);
		destroy_mutex(&data);
		free_all(&data);
	}
	else
	{
		printf("Input out of range!\n");
		return (1);
	}
	return (0);
}
