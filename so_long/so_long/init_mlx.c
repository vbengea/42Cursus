/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:49:36 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/22 19:57:10 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->vars.mlx = mlx_init();
	if (game->vars.mlx == NULL)
	{
		perror("Error: Failed to initialize MiniLibX\n");
		free_map(game);
		exit(0);
	}
	if (!valid_resolution(game))
	{
		perror("Error: Map too big for this screen!\n");
		free_map(game);
		exit(0);
	}
	game->vars.win = mlx_new_window(game->vars.mlx, game->size.x * 64,
			game->size.y * 64, "My first window");
	if (game->vars.win == NULL)
	{
		perror("Error: Failed to create a new window\n");
		free_map(game);
		free (game->vars.mlx);
		exit(0);
	}
	load_xpm(game);
	so_long(game);
	mlx_loop(game->vars.mlx);
}
