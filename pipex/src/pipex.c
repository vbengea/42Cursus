/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:53:19 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/01 12:41:43 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	exec_command();

char	***split_commands(int argc, char **argv)
{
	char	***splitted_commands;
	int		i;

	i = 2;
	splitted_commands = malloc(sizeof(char **) * argc + 1);
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

void	pipex(int argc, char **argv, char **env)
{
	char	***splitted_commands;
	char	**splitted_path;
	char	*full_path;
	int	i;

	splitted_path = ft_split(find_path(env), ':');
	if (!splitted_path)
		return ;
	i = 0;
	while (i < argc - 2)
	{
		fork();
		execute_command();
	}
	


}

