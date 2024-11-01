/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:14:25 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/01 12:51:30 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **a, bool print)
{
	t_stack_node	*last;

	if (a && *a && (*a)->next)
	{
		last = *a;
		while (last->next)
			last = last->next;
		if (last->prev)
		{
			last->prev->next = NULL;
			last->prev = NULL;
			last->next = *a;
			(*a)->prev = last;
			*a = last;
		}
	}
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool print)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (b && *b && (*b)->next)
	{
		last = *b;
		while (last->next)
			last = last->next;
		if (last->prev)
		{
			temp = last->prev;
			temp->next = NULL;
			last->prev = NULL;
			last->next = *b;
			(*b)->prev = last;
			*b = last;
		}
	}
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (print)
		write(1, "rrr\n", 4);
}
