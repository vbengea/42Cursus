/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:55:43 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/27 13:37:22 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;
	long			best_match;

	temp_a = *a;
	while (temp_a)
	{
		temp_b = *b;
		best_match = LONG_MIN;
		while (temp_b)
		{
			if (temp_b->value < temp_a->value && temp_b->value > best_match)
			{
				best_match = temp_b->value;
				temp_a->target_node = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (best_match == LONG_MIN)
			temp_a->target_node = find_max(&a);
		else
			temp_a->target_node = temp_b;
		temp_a = temp_a->next;
	}
}

void	set_target_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;
	long			best_match;

	temp_b = *b;
	while (temp_b)
	{
		temp_a = *a;
		best_match = LONG_MAX;
		while (temp_a)
		{
			if (temp_a->value > temp_b->value && temp_a->value < best_match)
			{
				best_match = temp_a->value;
				temp_b->target_node = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (best_match == LONG_MAX)
			temp_b->target_node = find_min(&a);
		else
			temp_b->target_node = temp_a;
		temp_b = temp_b->next;
	}
}
