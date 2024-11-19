/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:26:30 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/19 18:45:36 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	bool	is_valid_position(t_game *game, int x, int y, bool **visited)
{
	return (x >= 0 && x < game->size.x && y >= 0 && y < game->size.y
		&& game->map[y][x] != '1' && !visited[y][x]);
}

static	void	flood_fill(t_game *game, int x, int y, bool **visited)
{
	if (!is_valid_position(game, x, y, visited))
		return ;
	visited[y][x] = true;
	flood_fill(game, x + 1, y, visited);
	flood_fill(game, x - 1, y, visited);
	flood_fill(game, x, y + 1, visited);
	flood_fill(game, x, y - 1, visited);
}

static	bool	**alocate_visited(t_game *game)
{
	bool	**visited;
	int		i;
	int		j;

	visited = (bool **)malloc(game->size.y * sizeof(bool *));
	i = 0;
	while (i < game->size.y)
	{
		visited[i] = (bool *)malloc(game->size.x * sizeof(bool));
		j = 0;
		while (j < game->size.x)
		{
			visited[i][j] = false;
			j++;
		}
		i++;
	}
	return (visited);
}

static	void	free_visited(bool **visited, int size_y)
{
	int	i;

	i = 0;
	while (i < size_y)
	{
		free (visited[i]);
		i++;
	}
	free (visited);
}

bool	is_solvable(t_game *game)
{
	bool	**visited;
	bool	result;

	visited = alocate_visited(game);
	find_start_end(game);
	flood_fill(game, game->start.x, game->start.y, visited);
	result = check_items_and_exit(game, visited);
	free_visited(visited, game->size.y);
	return (result);
}
