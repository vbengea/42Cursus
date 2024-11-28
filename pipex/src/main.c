/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:34:27 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/28 18:41:26 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int i = 0;

	if (argc > 0 && argv[0])
	{
		printf("\n");
	}
	while (env[i])
	{
		printf("Line %d: %s\n", i, env[i]);
		i++;
	}
	return (0);
}