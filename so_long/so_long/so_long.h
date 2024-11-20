/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:31:30 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/20 10:11:04 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_game
{
	int		fd;
	bool	same_line_length;
	char	**map;
	t_vars	vars;
	t_point	size;
	t_point	start;
	t_point	end;
	t_img	bg;
}	t_game;

bool	valid_extension(char *file_name);
bool	valid_map(t_game *game);
bool	is_solvable(t_game *game);
void	init_map(t_game *game, char *file_name);
bool	at_least_one_item(t_game *game);
void	find_start_end(t_game *game);
bool	check_items_and_exit(t_game *game, bool **visited);
void	init_mlx(t_game *game);
void	free_map(t_game *map);
void	free_mlx(t_game *game);

/* EVENTS */
int	key_press(int keycode, void *param);

void	so_long(t_game *game);
int	close_window(void *param);

#endif