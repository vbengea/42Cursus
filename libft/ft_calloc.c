/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:41:14 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/21 11:04:21 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
	void    *ptr;
	
	if (!(ptr = (void *)malloc(size * nmemb)))
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
