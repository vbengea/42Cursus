/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:14:25 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/22 17:45:45 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_stack_node **a)
{
    t_stack_node *tmp;
    t_stack_node *last;

    if (a && *a && (*a)->next)
    {
        tmp = *a;
        last = *a;
        while (last->next->next)
            last = last->next;
        *a = last->next;
        last->next = NULL;
        (*a)->next = tmp;
    }
}

void    rrb(t_stack_node **b)
{
    t_stack_node *tmp;
    t_stack_node *last;

    if (b && *b && (*b)->next)
    {
        tmp = *b;
        last = *b;
        while (last->next->next)
            last = last->next;
        *b = last->next;
        last->next = NULL;
        (*b)->next = tmp;
    }
}

void    rrr(t_stack_node **a, t_stack_node **b)
{
    rra(a);
    rrb(b);
}