/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:53:31 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/11 18:36:31 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>
// #include <stdio.h>

static	int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (!s)
		return (0);
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

static	int	get_word_len(char const *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] != sep && s[i] != '\0')
		i++;
	return (i);
}

static void	free_split_array(char **split_array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}

static	int	add_word(char const **s, char c, char **split_array, int i)
{
	int	word_len;

	word_len = get_word_len(*s, c);
	split_array[i] = ft_substr(*s, 0, word_len);
	if (!split_array[i])
	{
		free_split_array(split_array, i);
		return (0);
	}
	*s += word_len;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split_array;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	split_array = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split_array)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && !add_word(&s, c, split_array, i++))
			return (NULL);
	}
	split_array[i] = NULL;
	return (split_array);
}

// int main(void)
// {
//     const char *t = "hello,world,again,test";
//     char **p = ft_split(t, ',');
//     printf("%s\n", p[0]);
//     printf("%s\n", p[1]);
//     printf("%s\n", p[2]);
// 	printf("%s\n", p[3]);
//     return 0; 
// }