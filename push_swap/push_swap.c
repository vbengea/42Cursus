/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:29:46 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/02 19:34:51 by vbcvali          ###   ########.fr       */
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
/* While there are more than 3 elements in stack A, push them to B
in descending order. When 3 are left, sort them and push back 
from B to A. Refresh current position and bring min node on top.*/

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
/* Two identical if condition in case there are 4 or 5 arguments
Call push_swap_2 because together there are more than 25 lines. */

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
