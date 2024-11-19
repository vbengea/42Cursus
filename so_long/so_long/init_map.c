/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:15:11 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/19 18:42:31 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	free_rest(t_game *game, int i)
{
	game->map[i] = NULL;
	while (++i < 20)
	{
		game->map[i] = NULL;
		free (game->map[i]);
	}
}

/* When assigning the value to MAP->SIZE.X i cast the result to an int
	and subtract one to ignore the new line char at the end of each line */
void	init_map(t_game *game, char *file)
{
	int	i;

	game->fd = open(file, O_RDONLY);
	game->map = malloc(sizeof(char *) * 20);
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
	free_rest(game, i);
}
