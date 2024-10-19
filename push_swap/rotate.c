/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:09:32 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/19 20:12:00 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_list **a)
{
    t_list *tmp;
    t_list *last;

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

void    rb(t_list **b)
{
    t_list *tmp;
    t_list *last;

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

void    rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}