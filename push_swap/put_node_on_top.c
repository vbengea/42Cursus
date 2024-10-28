/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_node_on_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:48:01 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/28 20:52:11 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_node_on_top(t_stack_node **stack,
		t_stack_node *top, char stack_name)
{
	t_stack_node	*temp;

	temp = *stack;
	while (temp != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(&temp, true);
			else
				rra(&temp, true);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				ra(&temp, true);
			else
				rra(&temp, true);
		}
		temp = temp->next;
	}
}
