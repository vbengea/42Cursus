/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:35:53 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/20 10:37:58 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrchr(const char *s, int c)
{
    char *last_match;

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

