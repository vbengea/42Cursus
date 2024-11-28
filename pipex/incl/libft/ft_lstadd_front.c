/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:44:47 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/09 13:21:05 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list_libft **lst, t_list_libft *new)
{
	new->next = *lst;
	*lst = new;
}

// new points to content of lst
// lst point to new