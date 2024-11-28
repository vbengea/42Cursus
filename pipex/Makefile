# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 18:08:25 by vbcvali           #+#    #+#              #
#    Updated: 2024/11/28 18:39:04 by vbcvali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCL_DIR = incl
LIB_DIR = incl/libft
LIB_MAKEFILE = $(LIB_DIR)/Makefile
LIB = $(LIB_DIR)/libft.a

OBJ_DIR = obj
BIN_DIR = bin

NAME = $(BIN_DIR)/pipex

SRCS = $(SRC_DIR)/main.c

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

all: $(LIB) $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) -o $@

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJ_DIR)/*.o 

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re