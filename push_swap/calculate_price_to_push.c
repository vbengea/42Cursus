/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_price_to_push.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:22:01 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/01 13:25:30 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Let's say we have a stack with 10 numbers
We iterate through the stack and set the price for each node.
The price is the amount of moves it takes to bring the node on top.
If the node is in the second position the price initially would be 2 because
	it takes 2 moves to bring it on top. (ra, ra)
If the node is in the poistion 9, it's bellow the median and we should 
	reverse rotate. The price would be the len of the stack minus the 
	current position
After that we check the target node:
	If is above median we add to the push price the current position of
	the target node.
	If is bellow median we add to the push price the rest of the len and
	the target current position*/
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
			temp_a->push_price += len_b - temp_a->target_node->current_position;
		temp_a = temp_a->next;
	}
}
/* Set cheapest iterates through the given stack and initially sets
all nodes atribute cheapest to false in order to avoid getting a 
false cheapest. Then iteerates again and sets the cheapest to True. */
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
