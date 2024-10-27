/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:29:46 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/27 13:41:04 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(&a);
	if (len > 3)
	{
		pb(&a, &b);
		len--;
	}
	if (len > 3)
	{
		pb(&a, &b);
		len--;
	}
	while (len > 3)
	{
		set_target_a(&a, &b);
		get_cheapest(&b);
		prepare_for_push(&b);
		pb(&a, &b);
	}
}