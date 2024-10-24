/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:14:25 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/24 10:41:03 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **a)
{
	t_stack_node	*last;

	if (a && *a && (*a)->next)
	{
		last = *a;
		while (last->next)
			last = last->next;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *a;
		(*a)->prev = last;
		*a = last;
	}
	write (1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (b && *b && (*b)->next)
	{
		last = *b;
		while (last->next)
			last = last->next;
		temp = last->prev;
		temp->next = NULL;
		last->prev = NULL;
		last->next = *b;
		(*b)->prev = last;
		*b = last;
	}
	write (1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rra(a);
	rrb(b);
	write (1, "rra\n", 4);
	write (1, "rrb\n", 4);
}
