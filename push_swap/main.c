/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:22 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/24 10:48:25 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	stack_init(&a, argv + 1, argc == 2);
	if (!stack_sorted(&a))
	{
		if (stack_len(&a) == 2)
			sa(&a);
		else if (stack_len(&a) == 3)
			sort_three(&a);
		// else if (stack_len(a) == 4)
		// 	sort_four(&a, &b);
		// else if (stack_len(a) == 5)
		// 	sort_five(&a, &b);
		// else
		// 	push_swap(&a, &b);
	}
	free_stack(&a);
}
