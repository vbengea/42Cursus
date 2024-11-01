/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:26:38 by vbengea           #+#    #+#             */
/*   Updated: 2024/11/01 12:16:59 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*temp;

	temp = *a;
	if (temp->value > temp->next->value)
	{
		if (temp->next->value > temp->next->next->value)
		{
			sa(a, true);
			rra(a, true);
		}
		else if (temp->value > temp->next->next->value)
			ra(a, true);
		else
			sa(a, true);
	}
	else
	{
		if (temp->value > temp->next->next->value)
			rra(a, true);
		else if (temp->next->value > temp->next->next->value)
		{
			sa(a, true);
			ra(a, true);
		}
	}
}
