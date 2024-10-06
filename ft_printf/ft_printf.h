/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:27:54 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/06 11:28:56 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		print_format(char c, va_list ap);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int n, int uppercase);
int		ft_putptr(void *ptr);
int		ft_putstr(char *str);

#endif