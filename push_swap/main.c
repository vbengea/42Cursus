/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:22 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/30 12:47:13 by vbcvali          ###   ########.fr       */
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
			sa(&a, true);
		else if (stack_len(&a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}

// void print_stack(t_stack_node *a)
// {
//     printf("Stack state:\n");
//     while (a)
//     {
//         printf("Value: %d, Prev: %p, Next: %p\n", a->value, (void*)a->prev, (void*)a->next);
//         a = a->next;
//     }
// }

// int	main(int argc, char **argv)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	else if (argc == 2)
// 		argv = split(argv[1], ' ');
// 	stack_init(&a, argv + 1, argc == 2);
// 	set_current_pos(&a);
// 	stack_init(&b, argv +1, argc == 2);
// 	print_stack(a);
// 	print_stack(b);
// 	pa(&a, &b, false);
// 	print_stack(a);
// 	print_stack(b);
	
// 	free_stack(&a);
// 	return (0);
// }


