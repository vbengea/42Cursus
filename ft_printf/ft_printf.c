/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 10:41:13 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/06 11:47:53 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%') // && (format + 1) != '\0'
			count += print_format(*(++format), ap);
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}
