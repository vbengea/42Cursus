# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 10:14:15 by vbengea           #+#    #+#              #
#    Updated: 2024/11/04 12:16:35 by vbengea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

HEADER_PRINTED = .header_printed

all: $(HEADER_PRINTED) $(NAME)

$(HEADER_PRINTED):
	@echo "\033[31m  _   _____  ______   _____   __   ____"
	@echo "\033[32m | | / / _ )/ ___/ | / / _ | / /  /  _/"
	@echo "\033[33m | |/ / _  / /__ | |/ / __ |/ /___/ /"  
	@echo "\033[34m |___/____/\___/ |___/_/ |_/____/___/"  
	@echo "\033[0m"
	@touch $(HEADER_PRINTED)

$(NAME): $(OBJS)
	@echo "\033[36mLinking object files to create executable...\033[0m"
	@echo "\033[32m$(CC) $(CFLAGS) \033[0m"
	@for obj in $(OBJS); do \
		echo "\033[32m$$obj \033[0m"; \
	done
	@echo "\033[32m-o $(NAME)\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@echo "\033[35mCompiling $<...\033[0m"
	@echo "\033[32m$(CC) $(CFLAGS) -c $< -o $@\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[35mCleaning object files...\033[0m"
	@for obj in $(OBJS); do \
		echo "\033[31mrm -f $$obj \033[0m"; \
	done
	@rm -f $(HEADER_PRINTED)
	@rm -f $(OBJS)

fclean: clean
	@echo "\033[35mCleaning executable...\033[0m"
	@echo "\033[31mrm -f $(NAME)\033[0m"
	@rm -f $(NAME)
	@rm -f $(HEADER_PRINTED)

clear:
	clear

re: fclean clear all

.PHONY: all clean fclean re clear
