/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/10/25 11:15:16 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/25 14:34:14 by vbcvali          ###   ########.fr       */
=======
/*   Created: 2024/10/27 12:29:46 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/30 14:29:19 by vbcvali          ###   ########.fr       */
>>>>>>> Turk
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
static	void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		reverse_rotate(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	pb(a, b);
}

static	void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static	void	min_on_top(t_stack_node **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

=======
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

>>>>>>> Turk
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(a);
<<<<<<< HEAD
	if (len-- > 3 && !stack_sorted(a))
		pb(a, b);
	if (len-- > 3 && !stack_sorted(a))
		pb(a, b);
	while (len-- > 3 && !stack_sorted(a))
	{
		init_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_position(*a);
	min_on_top(a);
=======
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
>>>>>>> Turk
}
