/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:34:27 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/11 19:05:04 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	free_all(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	if (pipex->splitted_commands)
	{
		while (pipex->splitted_commands[i])
		{
			j = 0;
			while (pipex->splitted_commands[i][j])
			{
				free(pipex->splitted_commands[i][j]);
				j++;
			}
			free(pipex->splitted_commands[i]);
			i++;
		}
	}
	free(pipex->splitted_commands);
	i = 0;
	while (pipex->splitted_path && pipex->splitted_path[i])
		free(pipex->splitted_path[i++]);
	free(pipex->splitted_path);
}

char	*find_path(char **env)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	if (!env || !env[i])
		return (NULL);
	while (env[i])
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		if (path != NULL)
			return (path + 5);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
	{
		ft_printf("Usage: ./pipex INFILE CMND1 CMND2 OUTFILE\n");
		exit (0);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		if (access(argv[1], F_OK) == -1)
		{
			perror("INFILE");
			exit (ENOENT);
		}
		if (access(argv[1], R_OK) == -1)
		{
			perror("INFILE");
			exit (13);
		}
	}
	pipex(argc, argv, env);
	return (0);
}
