/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:44:23 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/19 18:58:51 by vbcvali          ###   ########.fr       */
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

int	close_window(void *param)
{
	t_game *game = (t_game *)param;
	mlx_loop_end(game->vars.mlx);
	return (0);
}

void	so_long(t_game *game)
{
	mlx_hook(game->vars.win, 17, 0, close_window, game);
	mlx_key_hook(game->vars.win, key_press, NULL);
	mlx_string_put(game->vars.mlx, game->vars.win, 100, 100, 0xFFFFFF, "Hello, world!");

}