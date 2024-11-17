/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:00:25 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/15 14:01:10 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	at_least_one_item(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if (map->map[y][x] == 'C')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

void	find_start_end(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->start.x = j;
				map->start.y = i;
			}
			if (map->map[i][j] == 'E')
			{
				map->end.x = j;
				map->end.y = i;
			}
			j++;
		}
		i++;
	}
}

bool	check_items_and_exit(t_map *map, bool **visited)
{
	bool	all_items_collected;
	bool	exit_reachable;
	int		y;
	int		x;

	all_items_collected = true;
	exit_reachable = false;
	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if (map->map[y][x] == 'C' && !visited[y][x])
				all_items_collected = false;
			if (map->map[y][x] == 'E' && visited[y][x])
				exit_reachable = true;
			x++;
		}
		y++;
	}
	return (all_items_collected && exit_reachable);
}
