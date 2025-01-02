# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 10:33:50 by vbcvali           #+#    #+#              #
#    Updated: 2025/01/02 19:17:10 by vbcvali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
INCL_DIR = incl
OBJ_DIR = obj
BIN_DIR = bin

NAME = $(BIN_DIR)/philo

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/valid_input.c \
		$(SRC_DIR)/ft_atol.c \
		$(SRC_DIR)/time/ft_usleep.c \
		$(SRC_DIR)/time/get_current_time.c \
		$(SRC_DIR)/init/init_data.c \
		$(SRC_DIR)/init/init_philos.c \
		$(SRC_DIR)/init/init_threads.c \
		$(SRC_DIR)/init/init_forks.c \
		$(SRC_DIR)/init/init_program.c \
		$(SRC_DIR)/routine/routine.c \
		$(SRC_DIR)/clean/destroy_mutex.c \
		$(SRC_DIR)/clean/free_all.c \
		$(SRC_DIR)/actions/eat.c \
		$(SRC_DIR)/actions/sleep.c \
		$(SRC_DIR)/routine/monitor_routine.c \
		$(SRC_DIR)/join_threads/join.c

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(NAME): $(OBJS) | $(BIN_DIR)
	@$(CC) $(OBJS) -o $@
	@echo "Philosophers compiled"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects removed"

fclean: clean
	@rm -rf $(NAME) $(OBJ_DIR) $(BIN_DIR)
	@echo "Objects and executable removed"

re: fclean all

.PHONY: all clean fclean re

