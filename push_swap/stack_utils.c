/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:08:14 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/23 11:37:29 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node    *find_last(t_stack_node **a)
{
    t_stack_node    *temp;

    if (a == NULL || *a == NULL)
        return (NULL);
    temp = *a;
    while (temp->next != NULL)
        temp = temp->next;
    return (temp);
}

void    append_node(t_stack_node **a, int nbr)
{
    t_stack_node    *last_node;
    t_stack_node    *new_node;

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