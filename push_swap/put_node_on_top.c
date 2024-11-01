/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_node_on_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:48:01 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/01 12:17:35 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_node_on_top(t_stack_node **stack,
		t_stack_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}
