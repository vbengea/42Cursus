# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 10:14:15 by vbengea           #+#    #+#              #
#    Updated: 2024/10/24 10:21:07 by vbengea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sort.a

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
		swap.c

OBJS = $(SRCS:.c=.o)

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re