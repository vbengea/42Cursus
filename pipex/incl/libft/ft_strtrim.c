/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:08:25 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/25 12:54:28 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!set || !s1)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s1) - 1;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	while (ft_strchr(set, s1[j]) && j > i)
		j--;
	return (ft_substr((char *)s1, i, j - i + 1));
}
