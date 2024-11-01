/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/10/25 12:31:34 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/25 14:00:25 by vbcvali          ###   ########.fr       */
=======
/*   Created: 2024/10/27 11:27:01 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/27 13:37:41 by vbcvali          ###   ########.fr       */
>>>>>>> Turk
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
=======
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
>>>>>>> Turk
	}
	return (min_node);
}

<<<<<<< HEAD
t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MAX;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
=======
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
>>>>>>> Turk
	}
	return (max_node);
}
