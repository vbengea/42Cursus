/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_price_to_push.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:22:01 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/01 12:22:07 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_price_to_push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_a;
	int				len_a;
	int				len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
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
