/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:53:19 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/03 12:20:18 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	pipex->splitted_path = ft_split(find_path(env), ':');
	if (!pipex->splitted_path)
	{
		perror("Split path");
		exit(12);
	}
	pipex->splitted_commands = split_commands(argc, argv);
	if (!pipex->splitted_commands)
	{
		perror("Split commands");
		free_all(pipex);
		exit (12);
	}
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (pipex->infile < 0 || pipex->outfile < 0)
	{
		perror("Open");
		free_all(pipex);
		exit (9);
	}
}

void	child_process(t_pipex *pipex, int argc, int i, char **env)
{
	if (i == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->infile);
	}
	else
	{
		dup2(pipex->prev_pipefd[0], STDIN_FILENO);
		close(pipex->prev_pipefd[0]);
	}
	if (i == argc - 4)
	{
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->outfile);
	}
	else
	{
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		close(pipex->pipefd[1]);
	}
	exec_command(pipex, i, env);
}

void	parent_process(t_pipex *pipex, int i, int argc)
{
	if (i > 0)
		close(pipex->prev_pipefd[0]);
	if (i < argc - 4)
	{
		pipex->prev_pipefd[0] = pipex->pipefd[0];
		pipex->prev_pipefd[1] = pipex->pipefd[1];
	}
	close(pipex->pipefd[1]);
}

void	exec_command(t_pipex *pipex, int i, char **env)
{
	pipex->full_path = get_full_path(pipex->splitted_path, \
			pipex->splitted_commands[i][0]);
	if (!pipex->full_path)
	{
		perror("get_full_path");
		free_all(pipex);
		exit(EXIT_FAILURE);
	}
	execve(pipex->full_path, pipex->splitted_commands[i], env);
	perror("execve");
	free_all(pipex);
	exit(EXIT_FAILURE);
}

void	pipex(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	init_pipex(&pipex, argc, argv, env);
	i = 0;
	while (i < argc - 3)
	{
		if (i < argc - 4)
			create_pipe(&pipex);
		create_fork(&pipex);
		if (pipex.pid == 0)
			child_process(&pipex, argc, i, env);
		else
			parent_process(&pipex, i, argc);
		i++;
	}
	close_and_wait(&pipex, argc);
	free_all(&pipex);
}
