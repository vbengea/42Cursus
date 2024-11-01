# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 10:14:15 by vbengea           #+#    #+#              #
#    Updated: 2024/11/01 12:09:23 by vbcvali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	error_check.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		sort_three.c \
		split.c \
		stack_init.c \
		stack_utils.c \
		swap.c \
		main.c \
		find_min_max.c \
		set_current_pos.c \
		calculate_price_to_push.c \
		push_swap.c \
		rr_rrr_both.c \
		init.c \
		move_stacks.c \
		put_node_on_top.c \
		set_target.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
