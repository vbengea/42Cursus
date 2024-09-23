/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:56:03 by vbcvali           #+#    #+#             */
/*   Updated: 2024/09/23 08:32:17 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	return (nb * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     const char *tests[] = {
//         "42",
//         "   -42",
//         "4193 with words",
//         "words and 987",
//         "-91283472332",
//         "2147483647",
//         "-2147483648",
//         "0",
//         "+123",
//         "+++123"
//     };

//     for (int i = 0; i < 10; i++)
//     {
//         int my_result = ft_atoi(tests[i]);
//         int original_result = atoi(tests[i]);
//         printf("Test %d: \"%s\"\n", i + 1, tests[i]);
//         printf("ft_atoi: %d\n", my_result);
//         printf("atoi: %d\n", original_result);
//         printf("Match: %s\n\n", my_result == original_result ? "Yes" : "No");
//     }

//     return 0;
// }