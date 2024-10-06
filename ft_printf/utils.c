/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:29:20 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/06 12:18:41 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char c, va_list ap)
{
	if (c == 'c')
	{
		write(1, &(char){va_arg(ap, int)}, 1);
		return (1);
	}
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), c == 'X'));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == '%')
	{
		write(1, "%", 2);
		return (1);
	}
	else
		return (0);
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

int	ft_puthex(unsigned int n, int uppercase)
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
	count += write(1, "0x", 2);
	count += ft_puthex((unsigned long)ptr, 0);
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}
