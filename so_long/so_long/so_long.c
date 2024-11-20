/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:44:23 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/20 19:39:08 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_game *game)
{

	game->bg.img = mlx_xpm_file_to_image(game->vars.mlx, "textures/Blue.xpm", &game->bg.h, &game->bg.w);
	mlx_hook(game->vars.win, 17, 0, close_window, game);
	mlx_key_hook(game->vars.win, key_press, NULL);

	game->player.img = mlx_xpm_file_to_image(game->vars.mlx, "textures/Start-_Idle_.xpm", &game->player.h, &game->player.w);
	int i = 0;
	while (i < game->size.y)
	{
		int j = 0;
		while (j < game->size.x)
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->bg.img, j * game->bg.h, i * game->bg.w);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->player.img, j * game->bg.h, i * game->bg.w);
			j++;
		}
		i++;
	}
}

