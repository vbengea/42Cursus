/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:35:45 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/02 11:25:56 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <sys/wait.h>

typedef struct
{
	char	***splitted_commands;
	char	**splitted_path;
	char	*full_path;
	int		infile;
	int		outfile;
}	t_pipex;

char	*find_path(char **env);
void	pipex(int argc, char **argv, char **env);
char	***split_commands(int argc, char **argv);
void	free_all(t_pipex *pipex);

#endif
