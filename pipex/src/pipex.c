/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:53:19 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/02 13:07:43 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

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
	int	i;
	
	i = 0;
	while (splitted_path[i])
	{
		temp = ft_strjoin(splitted_path[i], "/");
		full = ft_strjoin(temp, command);
		free (temp);
		if (access(full, X_OK) == 0)
			return (full);
		i++;
	}
	return (NULL);
}

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	pipex->splitted_path = ft_split(find_path(env), ':');
	if (!pipex->splitted_path)
	{
		perror("Split path");
		exit(0);
	}
	pipex->splitted_commands = split_commands(argc, argv);
	if (!pipex->splitted_commands)
	{
		perror("Split commands");
		free_all(pipex);
		exit (0);
	}
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_RDWR | O_CREAT, 0777);
	if (pipex->infile < 0 || pipex->outfile < 0)
	{
		perror("Open");
		free_all(pipex);
		exit (0);
	}
}

void pipex(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	pid_t	pid;
	int		pipefd[2];
	int		prev_pipefd[2];
	int		i;

	init_pipex(&pipex, argc, argv, env);

	i = 0;
	while (i < argc - 3)
	{
		if (i < argc - 4)
		{
			if (pipe(pipefd) == -1)
			{
				perror("pipe");
				free_all(&pipex);
				exit(EXIT_FAILURE);
			}
		}

		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			free_all(&pipex);
			exit(EXIT_FAILURE);
		}

		if (pid == 0) // Child process
		{
			if (i == 0) // First command
			{
				dup2(pipex.infile, STDIN_FILENO);
				close(pipex.infile);
			}
			else // Intermediate commands
			{
				dup2(prev_pipefd[0], STDIN_FILENO);
				close(prev_pipefd[0]);
			}

			if (i == argc - 4) // Last command
			{
				dup2(pipex.outfile, STDOUT_FILENO);
				close(pipex.outfile);
			}
			else // Intermediate commands
			{
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[1]);
			}

			pipex.full_path = get_full_path(pipex.splitted_path, pipex.splitted_commands[i][0]);
			if (!pipex.full_path)
			{
				perror("get_full_path");
				free_all(&pipex);
				exit(EXIT_FAILURE);
			}

			execve(pipex.full_path, pipex.splitted_commands[i], env);
			perror("execve");
			free_all(&pipex);
			exit(EXIT_FAILURE);
		}
		else // Parent process
		{
			if (i > 0)
			{
				close(prev_pipefd[0]);
			}
			if (i < argc - 4)
			{
				prev_pipefd[0] = pipefd[0];
				prev_pipefd[1] = pipefd[1];
			}
			close(pipefd[1]);
		}
		i++;
	}

	close(pipex.infile);
	close(pipex.outfile);

	i = 0;
	while (i < argc - 3)
	{
		wait(NULL);
		i++;
	}

	free_all(&pipex);
}
