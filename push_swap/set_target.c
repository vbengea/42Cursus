/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:55:43 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/01 12:16:03 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;
	t_stack_node	*target_a;
	long			best_match;

	temp_a = *a;
	while (temp_a)
	{
		temp_b = *b;
		best_match = LONG_MIN;
		target_a = NULL;
		while (temp_b)
		{
			if (temp_b->value < temp_a->value && temp_b->value > best_match)
			{
				best_match = temp_b->value;
				target_a = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (target_a == NULL)
			temp_a->target_node = find_max(b);
		else
			temp_a->target_node = target_a;
		temp_a = temp_a->next;
	}
}

void	set_target_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;
	t_stack_node	*target_b;
	long			best_match;

	temp_b = *b;
	while (temp_b)
	{
		temp_a = *a;
		best_match = LONG_MAX;
		target_b = NULL;
		while (temp_a)
		{
			if (temp_a->value > temp_b->value && temp_a->value < best_match)
			{
				best_match = temp_a->value;
				target_b = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (target_b == NULL)
			temp_b->target_node = find_min(a);
		else
			temp_b->target_node = target_b;
		temp_b = temp_b->next;
	}
}
