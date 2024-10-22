/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:44:16 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/22 18:21:15 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    error_syntax(char *str)
{
    int i;

    i = 1;
    if (!str[0])
        return (true);
    if ((str[0] < '0' || str[0] > '9') && str[0] != '-' && str[0] != '+')
        return (true);
    else if ((str[0] == '-' || str[0] == '+') && !(str[i] >= '0' && str[i] <= '9'))
        return (true);
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (true);
        i++;
    }
    return (false);
}

bool    error_repetition(t_stack_node **a, int nbr)
{
    while (*a)
    {
        if ((*a)->value == nbr)
            return (true);
        a = &(*a)->next;
    }
    return (false);
}