/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:17:28 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/16 12:12:04 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_extension(char *file_name)
{
	char	*result;

	result = ft_strnstr(file_name, ".ber", ft_strlen(file_name));
	if (result == NULL)
		return (false);
	else
		return (true);
}

static	bool	is_rectangle(t_map *map)
{
	if (map->same_line_length && (map->size.y < map->size.x))
		return (true);
	return (false);
}

static	bool	valid_start_end(t_map *map)
{
	int	count_start;
	int	count_end;
	int	i;
	int	j;

	i = 0;
	count_end = 0;
	count_start = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				count_start++;
			if (map->map[i][j] == 'E')
				count_end++;
			j++;
		}
		i++;
	}
	if (count_end != 1 || count_start != 1)
		return (false);
	return (true);
}

static	bool	valid_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.y)
	{
		if (map->map[i][0] != '1' || map->map[i][map->size.x - 1] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->size.x)
	{
		if (map->map[0][i] != '1' || map->map[map->size.y - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	valid_map(t_map *map)
{
	if (!is_rectangle(map) || !valid_start_end(map) || !valid_walls(map)
		|| !at_least_one_item(map))
		return (false);
	if (is_solvable(map))
		return (true);
	return (false);
}
