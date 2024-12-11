/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:13:12 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/07 12:50:23 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	create_pipe(t_pipex *pipex)
{
	if (pipe(pipex->pipefd) == -1)
	{
		perror("pipe");
		free_all(pipex);
		exit(EXIT_FAILURE);
	}
}

void	create_fork(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
	{
		perror("fork");
		free_all(pipex);
		exit(EXIT_FAILURE);
	}
}

void	close_and_wait(t_pipex *pipex, int argc)
{
	int	i;

	close(pipex->infile);
	close(pipex->outfile);
	i = 0;
	while (i < argc - 3)
	{
		wait(NULL);
		i++;
	}
}

char	***split_commands(int argc, char **argv)
{
	char	***splitted_commands;
	int		i;

	i = 2;
	splitted_commands = malloc(sizeof(char **) * argc - 1);
	while (i < (argc - 1))
	{
		splitted_commands[i - 2] = ft_split(argv[i], ' ');
		i++;
	}
	splitted_commands[i - 2] = NULL;
	return (splitted_commands);
}

char	*get_full_path(char **splitted_path, char *command)
{
	char	*temp;
	char	*full;
	int		i;

	if (ft_strchr(command, '/') && (access(command, X_OK) == 0))
		return (ft_strdup(command));
	i = 0;
	if (splitted_path)
	{
		while (splitted_path[i])
		{
			temp = ft_strjoin(splitted_path[i], "/");
			full = ft_strjoin(temp, command);
			free (temp);
			if (access(full, X_OK) == 0)
				return (full);
			free (full);
			i++;
		}
	}
	return (NULL);
}
