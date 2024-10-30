/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_price_to_push.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:22:01 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/30 19:36:01 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	calculate_price_to_push(t_stack_node **a, t_stack_node **b)
// {
// 	t_stack_node	*temp;
// 	int				len_a;
// 	int				len_b;

// 	temp = *a;
// 	len_a = stack_len(a);
// 	len_b = stack_len(b);
// 	while (temp)
// 	{
// 		temp->push_price = temp->current_position;
// 		if (!(temp->above_median))
// 			temp->push_price = len_a - (temp->current_position);
// 		if (temp->target_node->above_median)
// 			temp->push_price += len_b - temp->target_node->current_position;
// 		else
// 			temp->push_price += len_b - (temp->target_node->current_position);
// 		temp = temp->next;
// 	}
// }

// void calculate_price_to_push(t_stack_node **a, t_stack_node **b)
// {
//     t_stack_node *temp;
//     int len_a;
//     int len_b;

//     temp = *a;
//     len_a = stack_len(a);
//     len_b = stack_len(b);
//     while (temp)
//     {
//         temp->push_price = temp->current_position;
//         if (!(temp->above_median))
//             temp->push_price = len_a - temp->current_position;
		
//         if (temp->target_node)
//         {
//             if (temp->target_node->above_median)
//                 temp->push_price += temp->target_node->current_position;
//             else
//                 temp->push_price += len_b - temp->target_node->current_position;
//         }
		
//         temp = temp->next;
//     }
// }

// void calculate_price_to_push(t_stack_node **a, t_stack_node **b)
// {
// 	t_stack_node *temp;
// 	int len_a;
// 	int len_b;

// 	temp = *a;
// 	len_a = stack_len(a);
// 	len_b = stack_len(b);
// 	while (temp)
// 	{
// 		temp->push_price = temp->current_position;
// 		if (!(temp->above_median))
// 			temp->push_price = len_a - temp->current_position;
		
// 		if (temp->target_node)
// 		{
// 			if (temp->target_node->above_median)
// 				temp->push_price += temp->target_node->current_position;
// 			else
// 				temp->push_price += len_b - temp->target_node->current_position;
// 		}
		
// 		temp = temp->next;
// 	}
// }

 void	calculate_price_to_push(t_stack_node **a, t_stack_node **b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	t_stack_node	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		temp_a->push_price = temp_a->current_position;
		if (!(temp_a->above_median))
			temp_a->push_price = len_a - (temp_a->current_position);
		if (temp_a->target_node->above_median) 
			temp_a->push_price += temp_a->target_node->current_position;
		else 
			temp_a->push_price += len_b - (temp_a->target_node->current_position);
		temp_a = temp_a->next;
	}
}

void	set_cheapest(t_stack_node **stack)
{
	t_stack_node	*cheapest;
	t_stack_node	*temp;
	long			cheapest_value;

	temp = *stack;
	if (!temp)
		return ;
	while (temp)
	{
		temp->cheapest_to_push = false;
		temp = temp->next;
	}
	temp = *stack;
	cheapest_value = LONG_MAX;
	while (temp)
	{
		if (temp->push_price < cheapest_value)
		{
			cheapest_value = temp->push_price;
			cheapest = temp;
		}
		temp = temp->next;
	}
	cheapest->cheapest_to_push = true;
}
