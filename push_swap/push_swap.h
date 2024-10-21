/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:29:03 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/21 16:19:40 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct  s_list
{
    void *content;
    struct s_list *next;
}   t_list;

void    pa(t_list **a, t_list **b);
void    pb(t_list **a, t_list **b);

void    rra(t_list **a);
void    rrb(t_list **b);
void    rrr(t_list **a, t_list **b);

void    sa(t_list **a);
void    sb(t_list **b);
void    ss(t_list **a, t_list **b);

void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a, t_list **b);

#endif