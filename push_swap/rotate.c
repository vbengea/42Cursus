/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:09:32 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/30 13:23:56 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **a, bool print)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (a && *a && (*a)->next)
	{
		temp = *a;
		last = *a;
		while (last->next)
			last = last->next;
		temp->next->prev = NULL;
		*a = temp->next;
		last->next = temp;
		temp->prev = last;
		temp->next = NULL;
	}
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool print)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (b && *b && (*b)->next)
	{
		temp = *b;
		last = *b;
		while (last->next)
			last = last->next;
		temp->next->prev = NULL;
		*b = temp->next;
		last->next = temp;
		temp->next = NULL;
	}
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	ra(a, false);
	rb(b, false);
		if (print)
			write(1, "rr\n", 3);
}
