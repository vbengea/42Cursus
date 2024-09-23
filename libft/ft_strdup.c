/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:02:27 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/23 08:46:15 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s);
	dest = malloc(((sizeof(char) * size) + 1));
	if (!(dest))
		return (NULL);
	ft_memcpy(dest, s, size);
	dest[size] = '\0';
	return (dest);
}
