/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:44:16 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/23 19:24:40 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	error_syntax(char *str)
{
	int	i;

	i = 1;
	if (!str[0])
		return (true);
	if ((str[0] < '0' || str[0] > '9') && str[0] != '-' && str[0] != '+')
		return (true);
	else if ((str[0] == '-' || str[0] == '+')
		&& !(str[i] >= '0' && str[i] <= '9'))
		return (true);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (true);
		i++;
	}
	return (false);
}

bool	error_repetition(t_stack_node **a, int nbr)
{
	while (*a)
	{
		if ((*a)->value == nbr)
			return (true);
		a = &(*a)->next;
	}
	return (false);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free (argv[i++]);
	free (argv - 1);
}

void	error_free(t_stack_node **a, char **argv, bool flag)
{
	free_stack(a);
	if (flag)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit (1);
}
