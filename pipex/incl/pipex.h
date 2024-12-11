/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:35:45 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/11 17:20:28 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipex
{
	char	***splitted_commands;
	char	**splitted_path;
	char	*full_path;
	int		pipefd[2];
	pid_t	pid;
	int		infile;
	int		outfile;
	bool	here_doc;
}	t_pipex;

char	*find_path(char **env);
void	pipex(int argc, char **argv, char **env);
char	***split_commands(int argc, char **argv);
void	free_all(t_pipex *pipex);
void	child_process(t_pipex *pipex, int argc, int i, char **env);
void	close_and_wait(t_pipex *pipex, int argc);
void	parent_process(t_pipex *pipex, int i, int argc);
void	exec_command(t_pipex *pipex, int i, char **env);
void	init_pipex(t_pipex *pipex, int argc, char **argv, char **env);
void	create_pipe(t_pipex *pipex);
void	create_fork(t_pipex *pipex);
char	*get_full_path(char **splitted_path, char *command);


#endif
