/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:56:56 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/24 12:26:20 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char            *str;

    i = 0;
    str = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
    if (!(str))
        return (NULL);
    while (i < ft_strlen((char *)s))
    {
        str[i] = f(i, str[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}
