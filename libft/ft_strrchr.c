/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:35:53 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/23 08:50:41 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_match;

	last_match = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_match = (char *)s;
		s++;
	}
	if (c == '\0')
		last_match = (char *)s;
	return (last_match);
}
