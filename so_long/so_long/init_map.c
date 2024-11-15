/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:15:11 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/15 12:20:37 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	free_rest(t_map *map, int i)
{
	map->map[i] = NULL;
	while (++i < 20)
	{
		map->map[i] = NULL;
		free (map->map[i]);
	}
}

/* When assigning the value to MAP->LINE_LENGTH i cast the result to an int
	and subtract one to ignore the new line char at the end of each line */
void	init_map(t_map *map, char *file)
{
	int	i;

	map->fd = open(file, O_RDONLY);
	map->map = malloc(sizeof(char *) * 20);
	if (map->fd == -1 || !map->map)
	{
		close(map->fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	map->same_line_length = true;
	map->size.y = 0;
	while (true)
	{
		map->map[i] = get_next_line(map->fd);
		if (map->map[i] == NULL)
			break ;
		if (i == 0)
			map->size.x = (int)(ft_strlen(map->map[i]) - 1);
		if (map->size.x != (int)(ft_strlen(map->map[i]) - 1))
			map->same_line_length = false;
		i++;
		map->size.y++;
	}
	free_rest(map, i);
}
