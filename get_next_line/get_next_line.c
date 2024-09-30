/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:23:17 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/30 20:04:27 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list *list)
{
	int		len;
	char	*next_str;

	if (!list)
		return (NULL);
	len = len_to_new_line(list);
	next_str = malloc(len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

int	found_newline(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buf);
		return ;
	}
	new_node->content = buf;
	new_node->next = NULL;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	clean_list(&list);
	return (next_line);
}

// int main(void)
// {
//     int fd;
//     int fd1;
//     char *line;
//     char *line1;
//     char *test0;
//     char *test1;

//     fd = open("test.txt", O_RDONLY);
//     fd1 = open("test1.txt", O_RDONLY);
//     line = get_next_line(fd);
//     line1 = get_next_line(fd);
//     test0 = get_next_line(fd1);
//     test1 = get_next_line(fd1);
//     printf("%s\n", line);
//     printf("%s\n", line1);
//     printf("%s\n", test0);
//     printf("%s\n", test1);
//     free(line);
//     free(line1);
//     free(test0);
//     free(test1);
//     return (0);
// }

/* GNL Read BUFFER_SIZE bytes and append them into a linked 
list witch is a static variable,
when a new line (\n) is found it stops reading.  */