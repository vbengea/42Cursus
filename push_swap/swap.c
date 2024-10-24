/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:25:25 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/24 10:42:54 by vbengea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a)
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
	write (1, "sa\n", 3);
}

void	sb(t_stack_node **b)
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
	write (1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	sa(a);
	sb(b);
	write (1, "sa\n", 3);
	write (1, "sb\n", 3);
}
