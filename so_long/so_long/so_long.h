/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:31:30 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/17 12:03:06 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

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

typedef struct s_map
{
	int		fd;
	bool	same_line_length;
	char	**map;
	t_vars	vars;
	t_point	size;
	t_point	start;
	t_point	end;
}	t_map;

bool	valid_extension(char *file_name);
bool	valid_map(t_map *map);
bool	is_solvable(t_map *map);
void	init_map(t_map *map, char *file_name);
bool	at_least_one_item(t_map *map);
void	find_start_end(t_map *map);
bool	check_items_and_exit(t_map *map, bool **visited);
void	init_mlx(t_map *map);
void	free_map(t_map *map);

void	so_long(t_map *map);

#endif