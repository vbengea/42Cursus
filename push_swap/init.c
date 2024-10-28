/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:00:02 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/28 19:44:41 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(t_stack_node **a, t_stack_node **b)
{
	set_current_pos(a);
	set_current_pos(b);
	set_target_a(a, b);
	calculate_price_to_push(a, b);
	set_cheapest(a);
}

void	init_b(t_stack_node **a, t_stack_node **b)
{
	set_current_pos(a);
	set_current_pos(b);
	set_target_b(a, b);
}