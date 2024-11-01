/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:42:06 by vbengea           #+#    #+#             */
/*   Updated: 2024/11/01 14:21:30 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_pos(t_stack_node **stack)
{
	t_stack_node	*temp;
	int				median;
	int				i;

	temp = *stack;
	i = 0;
	median = stack_len(&temp) / 2;
	while (temp)
	{
		temp->current_position = i;
		if (i <= median)
			temp->above_median = true;
		else
			temp->above_median = false;
		temp = temp->next;
		i++;
	}
}
