/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:17:08 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/23 08:44:30 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     const char *test = "Valentin";
//     int c = 'l';

//     char *result = ft_strchr(test, c);
//     printf("%p\n", result);
// }