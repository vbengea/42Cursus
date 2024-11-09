/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:03:35 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/20 19:09:24 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (dst1 == src1)
		return (dst);
	if (dst1 < src1)
	{
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dst1[len] = src1[len];
	}
	return (dst);
}
