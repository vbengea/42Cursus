/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:22:00 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/22 19:55:44 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

	// Offset is the difference in size to center the xpm.
void	render_player(t_game *game)
{
	int	i;
	int	j;
	int	offset;

	offset = (64 - 32) / 2;
	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
					game->player.img, j * 64 + offset, i * 64 + offset);
			j++;
		}
		i++;
	}
}

	// Offset is the difference in size to center the xpm.
void	render_walls(t_game *game)
{
	int	i;
	int	j;
	int	offset;

	offset = (64 - 42) / 2;
	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
					game->wall.img, j * 64 + offset, i * 64 + offset);
			j++;
		}
		i++;
	}
}

	// Offset is the difference in size to center the xpm.
void	render_items(t_game *game)
{
	int	i;
	int	j;
	int	offset;

	offset = (64 - 16) / 2;
	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
					game->item.img, j * 64 + offset, i * 64 + offset);
			j++;
		}
		i++;
	}
}

void	render_bg(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
					game->bg.img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	render_finish(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
					game->finish.img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
