/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:44:23 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/22 19:54:53 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	render_full_bg(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->bg.img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	so_long(t_game *game)
{
	game->moves = 0;
	mlx_hook(game->vars.win, 17, 0, close_window, game);
	mlx_hook(game->vars.win, 2, 1L << 0, key_press, game);
	render_full_bg(game);
	render_bg(game);
	render_player(game);
	render_walls(game);
	render_items(game);
	render_finish(game);
}
