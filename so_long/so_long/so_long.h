/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:31:30 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/22 19:46:09 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

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
	int		items;
	int		moves;
	t_vars	vars;
	t_point	size;
	t_point	start;
	t_point	end;
	t_img	bg;
	t_img	player;
	t_img	wall;
	t_img	item;
	t_img	finish;
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
bool	valid_chars(t_game *game);

/* EVENTS */
int	key_press(int keycode, void *param);
int	close_window(void *param);

/* LOAD XPM */
void	load_xpm(t_game *game);

/* MOVEMENTS */
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

/* RENDER */
void	render_player(t_game *game);
void	render_walls(t_game *game);
void	render_items(t_game *game);
void	render_bg(t_game *game);
void	render_finish(t_game *game);

void	so_long(t_game *game);
bool	valid_resolution(t_game *game);

#endif