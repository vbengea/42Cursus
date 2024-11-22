/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:12:00 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/22 10:34:59 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, void *param)
{
	t_game	*game;
	game = (t_game *)param;
	if (keycode == 65307)
		mlx_loop_end(game->vars.mlx);
	return (0);
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_loop_end(game->vars.mlx);
	return (0);
}
