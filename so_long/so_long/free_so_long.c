/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:58:12 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/22 10:25:36 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *map)
{
	int i;

	i = 0;
	while (i < map->size.y)
	{
		free (map->map[i]);
		i++;
	}
	free (map->map);
}
void	free_mlx(t_game *game)
{
	mlx_destroy_image(game->vars.mlx, game->bg.img);
	mlx_destroy_image(game->vars.mlx, game->finish.img);
	mlx_destroy_image(game->vars.mlx, game->player.img);
	mlx_destroy_image(game->vars.mlx, game->item.img);
	mlx_destroy_image(game->vars.mlx, game->wall.img);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free (game->vars.mlx);
	game->vars.mlx = NULL;
}