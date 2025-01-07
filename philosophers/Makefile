# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 10:33:50 by vbcvali           #+#    #+#              #
#    Updated: 2025/01/07 19:27:33 by vbcvali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
INCL_DIR = incl
OBJ_DIR = obj
BIN_DIR = bin

NAME = $(BIN_DIR)/philo

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/input/valid_input.c \
		$(SRC_DIR)/input/ft_atol.c \
		$(SRC_DIR)/time/ft_usleep.c \
		$(SRC_DIR)/time/get_current_time.c \
		$(SRC_DIR)/init/init_data.c \
		$(SRC_DIR)/init/init_philos.c \
		$(SRC_DIR)/init/init_threads.c \
		$(SRC_DIR)/init/init_forks.c \
		$(SRC_DIR)/init/init_program.c \
		$(SRC_DIR)/init/init_mutex.c \
		$(SRC_DIR)/routine/routine.c \
		$(SRC_DIR)/clean/destroy_mutex.c \
		$(SRC_DIR)/clean/free_all.c \
		$(SRC_DIR)/actions/eat.c \
		$(SRC_DIR)/actions/sleep.c \
		$(SRC_DIR)/routine/monitor_routine.c \
		$(SRC_DIR)/join_threads/join.c \
		$(SRC_DIR)/actions/think.c

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
	@echo "${GREEN}Philosophers compiled${NC}"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "${RED}Objects removed${NC}"

fclean: clean
	@rm -rf $(NAME) $(OBJ_DIR) $(BIN_DIR)
	@echo "${RED}Objects and executable removed${NC}"

re: fclean all

.PHONY: all clean fclean re

