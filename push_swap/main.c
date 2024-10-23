/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:22 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/23 12:21:03 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = split(argv[1], ' ');
    stack_init(&a, argv + 1, argc == 2); // argv + 1 Because the split function puts '\0' at the beginning of the array
    if (!stack_sorted(a))
    {
        if (stack_size(a) == 2)
            sa(&a);
        else if (stack_size(a) == 3)
            sort_three(&a);
        else if (stack_size(a) == 4)
            sort_four(&a, &b);
        else if (stack_size(a) == 5)
            sort_five(&a, &b);
        else
            push_swap(&a, &b);
    }
    free_stack(&a);
}