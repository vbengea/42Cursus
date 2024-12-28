# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 10:33:50 by vbcvali           #+#    #+#              #
#    Updated: 2024/12/28 11:12:08 by vbcvali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INCL_DIR = incl
OBJ_DIR = obj
BIN_DIR = bin

NAME = $(BIN_DIR)/philo

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/valid_input.c \
		$(SRC_DIR)/ft_atol.c

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(NAME): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -rf $(NAME) $(OBJ_DIR) $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re

