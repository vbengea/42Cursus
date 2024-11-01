/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:27:01 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/01 13:04:39 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_min(t_stack_node **stack)
{
	t_stack_node	*min_node;
	t_stack_node	*current;
	long			min_value;

	min_node = *stack;
	current = *stack;
	min_value = LONG_MAX;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node **stack)
{
	t_stack_node	*max_node;
	t_stack_node	*current;
	long			max_value;

	max_node = *stack;
	current = *stack;
	max_value = LONG_MIN;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}
