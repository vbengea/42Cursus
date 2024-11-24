/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:15:11 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/24 18:28:00 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	read_lines(char *file)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	lines = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		lines++;
	}
	close(fd);
	return (lines);
}

static	void	count_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->items = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			if (game->map[i][j] == 'C')
				game->items++;
			j++;
		}
		i++;
	}
}

/* When assigning the value to MAP->SIZE.X i cast the result to an int
	and subtract one to ignore the new line char at the end of each line */
void	init_map(t_game *game, char *file)
{
	int	i;

	game->map = malloc(sizeof(char *) * (read_lines(file) + 1));
	game->fd = open(file, O_RDONLY);
	if (game->fd == -1 || !game->map)
	{
		close(game->fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	game->same_line_length = true;
	game->size.y = 0;
	while (true)
	{
		game->map[i] = get_next_line(game->fd);
		if (game->map[i] == NULL)
			break ;
		if (i == 0)
			game->size.x = (int)(ft_strlen(game->map[i]) - 1);
		if (game->size.x != (int)(ft_strlen(game->map[i]) - 1))
			game->same_line_length = false;
		i++;
		game->size.y++;
	}
	count_items(game);
}
