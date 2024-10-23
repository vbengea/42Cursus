/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:57:05 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/23 19:28:49 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

SA = swap A // Swap the first two elements of stack A
    Does nothing if there is 1 or less elements.

SB = swap B // Swap the first two elements of stack B
    Does nothing if there is 1 or less elements.

ss = swap A & B at the same time

pa = push A // Takes the first element of stack B and puts it
    the first one in the stack A
        Does nothing if stack B it's empty

pb = push B // Takes the first element of stack A and puts it
    the first one in the stack B
        Does nothing if stack A it's empty

ra = rotate A // Moves all elements one position UP.
    The first one becomes the last one

rb = rotate B // Moves all elements one position UP
    The first one becomes the last one

rr = roatete A and B at the same time

rra = reverse rotate A // Moves all elements of stack A DOWN
    one position. The first one becomes the last one.

rrb = reverse rotate B // Moves all elements of stack B DOWN
    one position. The first one becomes the last one.
    
rrr = rra and rrb at the same time

*/