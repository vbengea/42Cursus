# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 18:08:25 by vbcvali           #+#    #+#              #
#    Updated: 2024/12/11 18:52:11 by vbcvali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
SRC_BONUS_DIR = src_bonus
INCL_DIR = incl
LIB_DIR = incl/libft
LIB_MAKEFILE = $(LIB_DIR)/Makefile
LIB = $(LIB_DIR)/libft.a

OBJ_DIR = obj
BIN_DIR = bin

NAME = $(BIN_DIR)/pipex

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/pipex.c \
		$(SRC_DIR)/utils.c

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

BONUS_SRCS = $(SRC_BONUS_DIR)/main_bonus.c \
				$(SRC_BONUS_DIR)/utils_bonus.c \
				$(SRC_BONUS_DIR)/pipex_bonus.c

BONUS_OBJS = $(patsubst $(SRC_BONUS_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_SRCS))

BONUS_NAME = $(BIN_DIR)/pipex_bonus

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

all: $(LIB) $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) -o $@

bonus: $(LIB) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIB)
	$(CC) $(BONUS_OBJS) $(LIB) -o $@

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJ_DIR)/*.o 

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -rf $(NAME) $(BONUS_NAME) $(BIN_DIR) $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re