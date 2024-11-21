/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:00:25 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/21 18:05:10 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	at_least_one_item(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->map[y][x] == 'C')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

void	find_start_end(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->start.x = j;
				game->start.y = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->end.x = j;
				game->end.y = i;
			}
			j++;
		}
		i++;
	}
}

bool	check_items_and_exit(t_game *game, bool **visited)
{
	bool	all_items_collected;
	bool	exit_reachable;
	int		y;
	int		x;

	all_items_collected = true;
	exit_reachable = false;
	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->map[y][x] == 'C' && !visited[y][x])
				all_items_collected = false;
			if (game->map[y][x] == 'E' && visited[y][x])
				exit_reachable = true;
			x++;
		}
		y++;
	}
	return (all_items_collected && exit_reachable);
}

bool	valid_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != 'C' 
				&& game->map[i][j] != 'E' && game->map[i][j] != 'P' 
				&& game->map[i][j] != '0')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
