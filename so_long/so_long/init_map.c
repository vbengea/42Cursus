/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:15:11 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/14 10:40:41 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map->lines = 0;
	while (true)
	{
		map->map[i] = get_next_line(map->fd);
		if (map->map[i] == NULL)
			break ;
		if (i == 0)
			map->line_length = (int)(ft_strlen(map->map[i]) - 1);
		if (map->line_length != (int)(ft_strlen(map->map[i]) - 1))
			map->same_line_length = false;
		i++;
		map->lines++;
	}
	map->map[i] = NULL;
	while (i++ < 20)
		free (map->map[i]);
}
