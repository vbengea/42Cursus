/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:21:00 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/22 12:03:08 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2 || !valid_extension(argv[1]))
		return (1);

	init_map(&game, argv[1]);

	if (!valid_map(&game))
	{
		ft_printf("Not a valid map !\n");
		free_map(&game);
		exit(0);
	}
	else
		printf("Valid map !\n");

	init_mlx(&game);

	free_map(&game);
	free_mlx(&game);

	return (0);
}