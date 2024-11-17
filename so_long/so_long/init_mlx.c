/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:49:36 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/17 13:00:33 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == 32)
		printf ("Space key pressed! 'Y\n");
	return (0);
}

int close_window(void *param)
{
	t_map *map = (t_map *)param;
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	mlx_destroy_display(map->vars.mlx);
	free(map->vars.mlx);
	map->vars.mlx = NULL;
	free_map(param);
	exit (0);
}

void	init_mlx(t_map *map)
{
	map->vars.mlx = mlx_init();

	if (map->vars.mlx == NULL) {
		fprintf(stderr, "Error: Failed to initialize MiniLibX\n");
		free_map(map);
		exit(0);
	}

	map->vars.win = mlx_new_window(map->vars.mlx, 800, 600, "My first window");
	if (map->vars.win == NULL) {
		fprintf(stderr, "Error: Failed to create a new window\n");
		free_map(map);
		exit(0);
	}
	mlx_hook(map->vars.win, 17, 0, close_window, map);
	mlx_key_hook(map->vars.win, key_press, NULL);
	mlx_string_put(map->vars.mlx, map->vars.win, 100, 100, 0xFFFFFF, "Hello, world!");

	printf("Testing\n");

	mlx_loop(map->vars.mlx);
}
