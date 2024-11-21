/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:01:17 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/21 20:03:41 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_xpm(t_game *game)
{
	game->player.img = mlx_xpm_file_to_image(game->vars.mlx, \
		"textures/Jump-_32x32_.xpm", \
		&game->player.w, &game->player.h);
	game->wall.img = mlx_xpm_file_to_image(game->vars.mlx, \
		"textures/Idle.xpm", \
		&game->wall.w, &game->wall.h);
	game->item.img = mlx_xpm_file_to_image(game->vars.mlx, \
		"textures/Mud-Particle.xpm", \
		&game->item.w, &game->item.h);
	game->bg.img = mlx_xpm_file_to_image(game->vars.mlx, \
		"textures/Blue.xpm", \
		&game->bg.w, &game->bg.h);
	game->finish.img = mlx_xpm_file_to_image(game->vars.mlx, \
		"textures/finish.xpm", \
		&game->finish.w, &game->finish.h);
}