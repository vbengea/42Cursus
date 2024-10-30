/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:29:46 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/29 11:27:12 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	minimum_on_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min(a);
	while ((*a)->value != min->value)
	{
		if (min->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

static	void	push_swap_2(t_stack_node **a, t_stack_node **b, int len)
{
	while (len > 3)
	{
		init_a(a, b);
		move_a_to_b(a, b);
		len--;
	}
	sort_three(a);
	while (*b)
	{
		init_b(a, b);
		move_b_to_a(a, b);
	}
	set_current_pos(a);
	minimum_on_top(a);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(a);
	if (len > 3)
	{
		pb(a, b, true);
		len--;
	}
	if (len > 3)
	{
		pb(a, b, true);
		len--;
	}
	push_swap_2(a, b, len);
}
