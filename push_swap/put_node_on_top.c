/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_node_on_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:48:01 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/30 10:58:56 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	put_node_on_top(t_stack_node **stack,
// 		t_stack_node *top, char stack_name)
// {
// 	t_stack_node	*temp;

// 	temp = *stack;
// 	while (temp != top && temp) // && temp;
// 	{
// 		if (stack_name == 'a')
// 		{
// 			if (top->above_median)
// 				ra(&temp, true);
// 			else
// 				rra(&temp, true);
// 		}
// 		else if (stack_name == 'b')
// 		{
// 			if (top->above_median)
// 				rb(&temp, true);
// 			else
// 				rrb(&temp, true);
// 		}
// 		temp = temp->next;
// 	}
// }

// void	put_node_on_top(t_stack_node **stack,
// 		t_stack_node *top, char stack_name)
// {
// 	t_stack_node	*temp;

// 	temp = *stack;
// 	while (temp != top) // && temp;
// 	{
// 		if (stack_name == 'a')
// 		{
// 			if (top->above_median)
// 				ra(&temp, true);
// 			else
// 				rra(&temp, true);
// 		}
// 		else if (stack_name == 'b')
// 		{
// 			if (top->above_median)
// 				rb(&temp, true);
// 			else
// 				rrb(&temp, true);
// 		}
// 	}
// }

// void	put_node_on_top(t_stack_node **stack,
// 		t_stack_node *top, char stack_name)
// {
// 	t_stack_node	*temp;

// 	temp = *stack;
// 	while (temp != top) // && temp;
// 	{
// 		if (stack_name == 'a')
// 		{
// 			if (top->above_median)
// 				ra(stack, true);
// 			else
// 				rra(stack, true);
// 		}
// 		else if (stack_name == 'b')
// 		{
// 			if (top->above_median)
// 				rb(stack, true);
// 			else
// 				rrb(stack, true);
// 		}
// 		temp = *stack;
// 	}
// }

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