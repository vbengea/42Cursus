/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:01:04 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/22 19:49:35 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	y;
	int	x;

	y = game->start.y;
	x = game->start.x;
	if (game->map[y - 1][x] == '1')
		return ;
	if (game->map[y - 1][x] == 'E')
	{
		if (game->items == 0)
			mlx_loop_end(game->vars.mlx);
		return ;
	}
	if (game->map[y - 1][x] == 'C' || game->map[y - 1][x] == '0')
	{
		if (game->map[y - 1][x] == 'C')
			game->items--;
		game->map[y - 1][x] = 'P';
		game->map[y][x] = '0';
		game->start.y = y - 1;
		game->moves++;
		ft_printf("Total moves: %d\n", game->moves);
	}
	render_bg(game);
	render_player(game);
}

void	move_down(t_game *game)
{
	int	y;
	int	x;

	y = game->start.y;
	x = game->start.x;
	if (game->map[y + 1][x] == '1')
		return ;
	if (game->map[y + 1][x] == 'E')
	{
		if (game->items == 0)
			mlx_loop_end(game->vars.mlx);
		return ;
	}
	if (game->map[y + 1][x] == 'C' || game->map[y + 1][x] == '0')
	{
		if (game->map[y + 1][x] == 'C')
			game->items--;
		game->map[y + 1][x] = 'P';
		game->map[y][x] = '0';
		game->start.y = y + 1;
		game->moves++;
		ft_printf("Total moves: %d\n", game->moves);
	}
	render_bg(game);
	render_player(game);
}

void	move_left(t_game *game)
{
	int	y;
	int	x;

	y = game->start.y;
	x = game->start.x;
	if (game->map[y][x - 1] == '1')
		return ;
	if (game->map[y][x - 1] == 'E')
	{
		if (game->items == 0)
			mlx_loop_end(game->vars.mlx);
		return ;
	}
	if (game->map[y][x - 1] == 'C' || game->map[y][x - 1] == '0')
	{
		if (game->map[y][x - 1] == 'C')
			game->items--;
		game->map[y][x - 1] = 'P';
		game->map[y][x] = '0';
		game->start.x = x - 1;
		game->moves++;
		ft_printf("Total moves: %d\n", game->moves);
	}
	render_bg(game);
	render_player(game);
}

void	move_right(t_game *game)
{
	int	y;
	int	x;

	y = game->start.y;
	x = game->start.x;
	if (game->map[y][x + 1] == '1')
		return ;
	if (game->map[y][x + 1] == 'E')
	{
		if (game->items == 0)
			mlx_loop_end(game->vars.mlx);
		return ;
	}
	if (game->map[y][x + 1] == 'C' || game->map[y][x + 1] == '0')
	{
		if (game->map[y][x + 1] == 'C')
			game->items--;
		game->map[y][x + 1] = 'P';
		game->map[y][x] = '0';
		game->start.x = x + 1;
		game->moves++;
		ft_printf("Total moves: %d\n", game->moves);
	}
	render_bg(game);
	render_player(game);
}
