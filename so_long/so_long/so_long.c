/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:44:23 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/20 09:59:39 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_game *game)
{
	game->bg.h = 64;
	game->bg.w = 64;
	game->bg.img = mlx_xpm_file_to_image(game->vars.mlx, "textures/Blue.xpm", &game->bg.h, &game->bg.w);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->bg.img, 400, 300);
	mlx_hook(game->vars.win, 17, 0, close_window, game);
	mlx_key_hook(game->vars.win, key_press, NULL);
}

