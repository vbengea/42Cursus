/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:21:37 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/11 19:43:07 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
	ft_printf("This is an unsigned int: %u\n", 42);
	ft_printf("This is an integer: %i\n", -42);
	ft_printf("Hello, %s!\n", "world");
	ft_printf("This is a %c\n", 'c');
	ft_printf("This is a %d\n", 42);
	ft_printf("This is a %x\n", 42);
	ft_printf("This is a %X\n", 42);
	ft_printf("This is a %p\n", "pointer");
	ft_printf("This is a %%\n");
	ft_printf("This is a %c %s %d %x %X %p %%\n", 'c', "string", 42, 42, 42, "pointer");

	// int count = ft_printf("This is an unsigned int: %u\n", 42);
	// printf("count: %d\n", count);
	// count = printf("This is an unsigned int: %u\n", 42);
	// printf("count: %d\n", count);


	ft_printf(" %% ");
	ft_printf("\n");
	ft_printf(" %%%% ");
	ft_printf("\n");
	ft_printf(" %% %% %% ");
	ft_printf("\n");
	ft_printf(" %%  %%  %% ");
	ft_printf("\n");
	ft_printf(" %%   %%   %% ");
	ft_printf("\n");
	ft_printf("%%");
	ft_printf("\n");
	ft_printf("%% %%");
	ft_printf("\n");
	ft_printf("Hola que tal esto es un texto de prueba%");
	//printf("Hola que tal esto es un texto de prueba%");
	ft_printf("%%");

	return (0);
}

// int main()
// {
//     int result;

//     result = ft_printf("Hello, world!\n");
//     printf("Result: %d\n", result);

//     result = ft_printf("Incomplete format: %\n");
//     printf("Result: %d\n", result);

//     return 0;
// }