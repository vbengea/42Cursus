/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:46:57 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/26 08:33:23 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
#include "libft.h"
// #include <stdio.h>

static char	*ft_str_number(int i, long n)
{
	char	*str_num;

	if (n == 0)
		return (ft_strdup("0"));
	str_num = (char *)malloc((i + 1) * sizeof(char));
	if (str_num == NULL)
		return (NULL);
	if (n < 0)
	{
		str_num[0] = '-';
		n = -n;
	}
	str_num[i] = '\0';
	while (n != 0)
	{
		str_num[--i] = n % 10 + '0';
		n = n / 10;
	}
	return (str_num);
}

char	*ft_itoa(int n)
{
	int		i;
	int		cpy;
	long	nl;

	nl = n;
	i = 0;
	cpy = n;
	while (cpy != 0)
	{
		cpy = cpy / 10;
		i++;
	}
	if (nl < 0)
		i++;
	return (ft_str_number(i, nl));
}

// int main(void)
// {
// 	char *s = ft_itoa(-2147483648);
// 	int j = 0;
// 	while (s[j] != '\0')
// 	{
// 		printf("%c", s[j]);
// 		j++;
// 	}
// 	// printf("%s\n", s);
// 	return 0;
// }