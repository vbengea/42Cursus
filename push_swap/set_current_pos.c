/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:42:06 by vbengea           #+#    #+#             */
/*   Updated: 2024/10/28 12:21:15 by vbengea          ###   ########.fr       */
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
		if (i < median)
			temp->above_median = true;
		else
			temp->above_median = false;
		temp = temp->next;
		i++;
	}
}