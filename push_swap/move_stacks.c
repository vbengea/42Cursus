/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:27:21 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/28 20:33:30 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		reverse_rotate_both(a, b, cheapest);
	put_node_on_top(a, cheapest, 'a');
	put_node_on_top(b, cheapest->target_node, 'b');
	pb(a, b);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	put_node_on_top(a, (*b)->target_node, 'a');
	pa(a, b);
}
