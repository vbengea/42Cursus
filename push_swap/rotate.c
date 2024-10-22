/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:09:32 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/22 17:45:33 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack_node **a)
{
    t_stack_node *tmp;
    t_stack_node *last;

    if (a && *a && (*a)->next)
    {
        tmp = *a;
        last = *a;
        while (last->next)
            last = last->next;
        *a = (*a)->next;
        last->next = tmp;
        tmp->next = NULL;
    }
}

void    rb(t_stack_node **b)
{
    t_stack_node *tmp;
    t_stack_node *last;

    if (b && *b && (*b)->next)
    {
        tmp = *b;
        last = *b;
        while (last->next)
            last = last->next;
        *b = (*b)->next;
        last->next = tmp;
        tmp->next = NULL;
    }
}

void    rr(t_stack_node **a, t_stack_node **b)
{
    ra(a);
    rb(b);
}