/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:53:51 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/28 10:59:40 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

int	main(int argc, char **argv)
{
	//t_philo	philos;

	if (argc < 5 || argc > 6 )
	{
		printf("Usage: ./philo [philosophers] [time to die] [time to eat]");
		printf(" [time to sleep] [(optional) number of times to eat]\n");
		return (0);
	}
	if (valid_input(argv))
		printf("The input is valid !\n");
		//init_philos(&philos);
	return (0);
}
