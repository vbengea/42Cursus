/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:26:30 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/15 12:20:41 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	bool	is_valid_position(t_map *map, int x, int y, bool **visited)
{
	return (x >= 0 && x < map->size.x && y >= 0 && y < map->size.y
		&& map->map[y][x] != '1' && !visited[y][x]);
}

static	void	flood_fill(t_map *map, int x, int y, bool **visited)
{
	if (!is_valid_position(map, x, y, visited))
		return ;
	visited[y][x] = true;
	flood_fill(map, x + 1, y, visited);
	flood_fill(map, x - 1, y, visited);
	flood_fill(map, x, y + 1, visited);
	flood_fill(map, x, y - 1, visited);
}

static	bool	**alocate_visited(t_map *map)
{
	bool	**visited;
	int		i;
	int		j;

	visited = (bool **)malloc(map->size.y * sizeof(bool *));
	i = 0;
	while (i < map->size.y)
	{
		visited[i] = (bool *)malloc(map->size.x * sizeof(bool));
		j = 0;
		while (j < map->size.x)
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

bool	is_solvable(t_map *map)
{
	bool	**visited;
	bool	result;

	visited = alocate_visited(map);
	find_start_end(map);
	flood_fill(map, map->start.x, map->start.y, visited);
	result = check_items_and_exit(map, visited);
	free_visited(visited, map->size.y);
	return (result);
}
