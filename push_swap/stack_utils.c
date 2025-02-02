/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:08:14 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/01 12:52:02 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (stack == NULL || *stack == NULL)
		return (NULL);
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	append_node(t_stack_node **a, int nbr)
{
	t_stack_node	*last_node;
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = nbr;
	new_node->next = NULL;
	if (*a == NULL)
	{
		new_node->prev = NULL;
		*a = new_node;
	}
	else
	{
		last_node = find_last(a);
		new_node->prev = last_node;
		last_node->next = new_node;
	}
}

int	stack_len(t_stack_node **stack)
{
	t_stack_node	*temp;
	int				len;

	if (stack == NULL || *stack == NULL)
		return (0);
	len = 0;
	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

bool	stack_sorted(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (stack == NULL || *stack == NULL)
		return (true);
	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->next->value < temp->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}

t_stack_node	*get_cheapest(t_stack_node **stack)
{
	t_stack_node	*temp;

	temp = *stack;
	while (!temp->cheapest_to_push)
		temp = temp->next;
	return (temp);
}
