/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:29:20 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/09 12:53:38 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putunsigned(n / 10);
	write(1, &(char){n % 10 + '0'}, 1);
	return (count + 1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	write(1, &(char){n % 10 + '0'}, 1);
	return (count + 1);
}

int	ft_puthex(unsigned long long n, int uppercase)
{
	int	count;

	count = 0;
	if (n > 15)
		count += ft_puthex(n / 16, uppercase);
	if (n % 16 < 10)
		write(1, &(char){n % 16 + '0'}, 1);
	else
	{
		if (uppercase)
			write(1, &(char){n % 16 - 10 + 'A'}, 1);
		else
			write(1, &(char){n % 16 - 10 + 'a'}, 1);
	}
	return (count + 1);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_puthex((unsigned long long)ptr, 0);
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str != '\0')
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}
