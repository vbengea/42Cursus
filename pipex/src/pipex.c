/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:53:19 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/14 13:25:59 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	pipex->splitted_path = ft_split(find_path(env), ':');
	pipex->splitted_commands = split_commands(argc, argv);
	if (!pipex->splitted_commands)
	{
		perror("Split commands");
		free_all(pipex);
		exit (12);
	}
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		perror ("INFILE");
		pipex->infile = open ("/dev/null", O_RDONLY);
	}
	pipex->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
}

void	child_process(t_pipex *pipex, int argc, int i, char **env)
{
	dup2(pipex->infile, STDIN_FILENO);
	if (i == argc - 4)
	{
		if (pipex->outfile < 0)
		{
			free_all (pipex);
			exit (1);
		}
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
	close (pipex->pipefd[1]);
	if (i > 0)
		close (pipex->infile);
	if (i < argc - 4)
		pipex->infile = pipex->pipefd[0];
	else
		close (pipex->pipefd[0]);
}

void	exec_command(t_pipex *pipex, int i, char **env)
{
	pipex->full_path = get_full_path(pipex->splitted_path, \
			pipex->splitted_commands[i][0]);
	if (!pipex->full_path)
	{
		perror("get_full_path");
		free_all(pipex);
		exit(127);
	}
	execve(pipex->full_path, pipex->splitted_commands[i], env);
	perror("execve");
	free_all(pipex);
	exit(127);
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
