/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:29:16 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/09 13:20:53 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstnew(void *content)
{
	t_list_libft	*new;

	new = malloc(sizeof(t_list_libft));
	if (!(new))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
