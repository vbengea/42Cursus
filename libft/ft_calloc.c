/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:41:14 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/23 08:37:12 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (NULL);
	else if (size != 0 && (total_size / size) != nmemb)
		return (NULL);
	ptr = malloc(total_size);
	if (!(ptr))
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
