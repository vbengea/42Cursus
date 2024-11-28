/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:24:53 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/09 13:26:08 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstmap(t_list_libft *lst, void *(*f)(void *),
					void (*del)(void *))
{
	t_list_libft	*new;
	t_list_libft	*tmp;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
