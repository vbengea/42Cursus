/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:02:27 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/21 12:20:43 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s)
{
    char *dest;
    size_t  size;

    size = ft_strlen(s);
    if (!(dest = malloc(((sizeof(char) * size) + 1))))
        return (NULL);
    ft_memcpy(dest, s, size);
    dest[size] = '\0';
    return (dest);
}