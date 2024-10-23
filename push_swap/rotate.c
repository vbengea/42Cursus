/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:09:32 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/23 19:25:44 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **a)
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
		temp->next = NULL;
	}
}

void	rb(t_stack_node **b)
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
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra(a);
	rb(b);
}
