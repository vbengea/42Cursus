/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:22 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/28 20:55:14 by vbcvali          ###   ########.fr       */
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

// int	main(int argc, char **argv)
// {
// 	t_stack_node	*a;
// 	//t_stack_node	*b;

// 	a = NULL;
// 	//b = NULL;
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	else if (argc == 2)
// 		argv = split(argv[1], ' ');
// 	stack_init(&a, argv + 1, argc == 2);
// 	set_current_pos(&a);
// 	t_stack_node *temp = a;
// 	while (temp)
// 	{
// 		printf(" Node value: %d\n Above median: %d\n Current index: %d\n", temp->value, temp->above_median, temp->current_position);
// 		temp = temp->next;
// 	}

// 	//printf("This is the minimum node: %d\n", find_min(&a)->value);
// 	//printf("This is the maximum node: %d\n", find_max(&a)->value);

// 	free_stack(&a);
// 	return (0);
// }