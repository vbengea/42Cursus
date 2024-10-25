/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:13:39 by vbcvali           #+#    #+#             */
/*   Updated: 2024/10/25 14:17:32 by vbcvali          ###   ########.fr       */
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
	int					final_position;
	int					push_price;
	bool				above_median;
	bool				cheapest_to_push;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}	t_stack_node;

char			**split(char *s, char c);

/* Commands */
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

/* Stack functions */
void			stack_init(t_stack_node **a, char **argv, bool flag);
void			append_node(t_stack_node **a, int nbr);
int				stack_len(t_stack_node **stack);
bool			stack_sorted(t_stack_node **stack);
void			current_position(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void			rotate(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			reverse_rotate(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			prep_for_push(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);
void			set_cheapest(t_stack_node *stack);
void			init_a(t_stack_node *a, t_stack_node *b);
void			init_b(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_cheapest(t_stack_node *stack);

/* Error checks */
bool			error_syntax(char *str);
bool			error_repetition(t_stack_node **a, int nbr);

/* Free memory */
void			error_free(t_stack_node **a, char **argv, bool flag);
void			free_stack(t_stack_node **stack);
void			free_argv(char **argv);

/* Sort functions */
void			sort_three(t_stack_node **a);
void			push_swap(t_stack_node **a, t_stack_node **b);

#endif