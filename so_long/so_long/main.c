/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:21:00 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/13 21:10:31 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

// bool	is_rectangular();

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->lines)
	{
		free (map->map[i]);
		i++;
	}
	free (map->map);
}





int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2 || !valid_extension(argv[1]))
		return (1);
	init_map(&map, argv[1]);
	if (valid_map(&map))
		printf("Valid map !\n");
		//so_long(map);
	else
		printf("Invalid map !\n");
	
	// printf("Line = %s\n", map.map[0]);
	// printf("Line length: %ld\n", ft_strlen(map.map[0]));
	// printf("Line length original strlen: %ld\n", strlen(map.map[0]));
	// printf("Length of word hola :%ld\n", strlen("1111111"));
	// printf("Map lines :%d\n", map.lines);
	// printf("Same line length: %d\n", map.same_line_length);
	free_map(&map);
	return (0);
}



















// int close_window(void *param)
// {
// 	(void)param;
// 	exit (0);
// }

// int key_press(int keycode, void *param)
// {
// 	(void)param;
// 	if (keycode == 32)
// 		printf ("Space key pressed! 'Y\n");
// 	return (0);
// }

// int main()
// {
// 	void *mlx;
// 	void *win;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 800, 600, "My first window");

// 	mlx_hook(win, 17, 0, close_window, NULL);

// 	mlx_key_hook(win, key_press, NULL);

// 	printf("Testing\n");

// 	mlx_loop(mlx);

// 	return (0);
// }