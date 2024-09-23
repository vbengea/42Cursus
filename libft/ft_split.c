/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:53:31 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/23 19:55:04 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>
// #include <stdio.h>

static int  count_words(char const *s, char c)
{
    int count = 0;
    int in_word = 0;

    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

static  int get_word_len(char const *s, char *sep)
{
    int i;

    i = 0;
    while (s[i] != *sep && s[i] != '\0') 
        i++;
    return (i);
}

char    **ft_split(char const *s, char c)
{
    char **split_array;
    int i;
    int j;
    int word_len;

    split_array = malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!split_array)
        return (NULL);
    i = 0;
    while (*s)
    {
        while (*s == c)
            s++;
        if (*s)
        {
            word_len = get_word_len(s, &c);
            split_array[i] = ft_substr(s, 0, word_len);
            if (!split_array[i])
                return (NULL);
            s += word_len;
            i++;
        }
    }
    split_array[i] = NULL;
    return (split_array);
}

// int main(void)
// {
//     const char *t = "hello world again";
//     char **p = ft_split(t, ' ');
//     printf("%s\n", p[0]);
//     printf("%s\n", p[1]);
//     printf("%s\n", p[2]);
//     return 0; 
// }