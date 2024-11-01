/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:25:25 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/01 12:18:26 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a, bool print)
{
	t_stack_node	*temp;

	if (a && *a && (*a)->next)
	{
		temp = (*a)->next;
		(*a)->next = temp->next;
		if (temp->next)
			temp->next->prev = *a;
		temp->prev = (*a)->prev;
		(*a)->prev = temp;
		temp->next = *a;
		*a = temp;
	}
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool print)
{
	t_stack_node	*tmp;

	if (b && *b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = *b;
		tmp->prev = (*b)->prev;
		(*b)->prev = tmp;
		tmp->next = *b;
		*b = tmp;
	}
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	sa(a, false);
	sb(b, false);
	if (print)
		write(1, "ss\n", 3);
}
