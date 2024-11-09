/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:21:00 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/08 13:22:33 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>


int close_window(void *param)
{
	(void)param;
	exit (0);
}

int key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == 65361)
		printf ("Space key pressed! 'Y\n");
	return (0);
}

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "My first window");
	
	mlx_hook(win, 17, 0, close_window, NULL);

	mlx_key_hook(win, key_press, NULL);

	mlx_loop(mlx);

	return (0);
}