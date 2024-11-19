/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:44:23 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/19 19:13:11 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_game *game)
{
	mlx_hook(game->vars.win, 17, 0, close_window, game);
	mlx_key_hook(game->vars.win, key_press, NULL);
}
