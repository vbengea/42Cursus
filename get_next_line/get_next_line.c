/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:23:17 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/30 13:42:24 by vbcvali          ###   ########.fr       */
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
	while (list)
	{
		if (ft_strchr(list->content, '\n'))
			return (1);
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
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
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
		if (!char_read)
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
	static t_list	*list;
	char			*next_line;

	list = NULL;
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
//     char *line;
//     char *test;

//     fd = open("test.txt", O_RDONLY);
//     line = get_next_line(fd);
//     test = get_next_line(fd);
//     printf("%s\n", line);
//     printf("%s\n", test);
//     return (0);
// }

/* GNL Read BUFFER_SIZE bytes and append them into a linked 
list or a static variable,
when a new line is found it stops reading.  
While strchr != '\n' append to the linked list*/