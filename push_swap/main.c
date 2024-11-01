/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:22 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/01 14:06:42 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* If input is invalid, exit the program.
If there is only 1 argument (argc == 2) i assume is a string
and call split. 
Split will start with the first position being '\0'
If there are more than 2 arguments, argv + 1 will skip the program
name. If there are only 2 arguments, argv + 1 will also work
because argv will be the result of split.
Init the stack with the flag (argc == 2) to know if i need to free
argv or not. */
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
			sa(&a, true);
		else if (stack_len(&a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
