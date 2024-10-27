/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:26:38 by vbengea           #+#    #+#             */
/*   Updated: 2024/10/27 10:34:10 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*temp;

	temp = *a;
	if (temp->value > temp->next->value)
	{
		temp = temp->next;
		if (temp->value > temp->next->value)
		{
			rra(a);
			rra(a);
			return ;
		}
		if (temp->value < temp->next->value)
		{
			if (temp->next->value > (*a)->value)
				sa(a);
			else
				ra(a);
		}
	}
	else
	{
		sa(a);
		ra(a);
	}
}

/* #include <stdio.h>

void	sort_three(t_stack_node **a)
{
	t_stack_node	*temp;

	temp = *a;
	if (temp->value > temp->next->value)
	{
		temp = temp->next;
		if (temp->value > temp->next->value)
		{
			rra(a);
			rra(a);
			printf("rra\nrra\n");
			return ;
		}
		if (temp->value < temp->next->value)
		{
			if (temp->next->value > (*a)->value)
			{
				sa(a);
				printf("sa\n");
			}
			else
			{
				ra(a);
				printf("ra\n");
			}
		}
	}
	else
	{
		sa(a);
		ra(a);
		printf("sa\nra\n");
	}
} */