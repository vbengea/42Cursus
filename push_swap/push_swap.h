/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:13:39 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/30 18:38:53 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest_to_push;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}	t_stack_node;

/* Function to split the arguments in **argv ////////////////////////////////*/
char			**split(char *s, char c);

/* Commands /////////////////////////////////////////////////////////////////*/
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);

/* Stack functions //////////////////////////////////////////////////////////*/
void			stack_init(t_stack_node **a, char **argv, bool flag);
void			append_node(t_stack_node **a, int nbr);
int				stack_len(t_stack_node **stack);
bool			stack_sorted(t_stack_node **stack);
t_stack_node	*find_min(t_stack_node **stack);
t_stack_node	*find_max(t_stack_node **stack);
t_stack_node	*get_cheapest(t_stack_node **stack);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			put_node_on_top(t_stack_node **stack,
					t_stack_node *top, char stack_name);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);

/*	Initializes the nodes from stack A & B; 
	Sets the index, the target and calculates the price for each move. */
void			init_a(t_stack_node **a, t_stack_node **b);
void			init_b(t_stack_node **a, t_stack_node **b);

// Set Target A sets the target node in stack B 
void			set_target_a(t_stack_node **a, t_stack_node **b);

// Set Target B the same but in stack A
void			set_target_b(t_stack_node **a, t_stack_node **b);

// Set an index for each node
void			set_current_pos(t_stack_node **stack);

/*	Calculates the node that takes the less amount of moves to get on top
	Each node has a target node. When we push the node, it's target must
	be on top. The function calculates the price for each node. */
void			calculate_price_to_push(t_stack_node **a, t_stack_node **b);

/*	This functions sets to True the atribute 
	cheapest_to_push on the cheapest node. */
void			set_cheapest(t_stack_node **stack);

/* Error checks /////////////////////////////////////////////////////////////*/

// Error syntax checks if is a valid number that can be passed to ft_atol.
bool			error_syntax(char *str);
// Error repetitios checks if a number is duplicated.
bool			error_repetition(t_stack_node **a, int nbr);

/* Free memory //////////////////////////////////////////////////////////////*/
void			error_free(t_stack_node **a, char **argv, bool flag);
void			free_stack(t_stack_node **stack);
void			free_argv(char **argv);

/* Sort functions ///////////////////////////////////////////////////////////*/
void			sort_three(t_stack_node **a);
void			push_swap(t_stack_node **a, t_stack_node **b);


/* TEMP */
void print_stack(t_stack_node *a);

#endif
