# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 18:45:23 by vbcvali           #+#    #+#              #
#    Updated: 2024/11/23 11:24:30 by vbcvali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iminilibx-linux
LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
MINILIBX_MAKEFILE = $(MINILIBX_DIR)/Makefile
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a
SRC_DIR = src
SRC_FILES = $(SRC_DIR)/init_map.c \
			$(SRC_DIR)/is_solvable.c \
			$(SRC_DIR)/validate_map.c \
			$(SRC_DIR)/validate_map_2.c \
			$(SRC_DIR)/so_long.c \
			$(SRC_DIR)/init_mlx.c \
			$(SRC_DIR)/free_so_long.c \
			$(SRC_DIR)/events.c \
			$(SRC_DIR)/render.c \
			$(SRC_DIR)/load_xpm.c \
			$(SRC_DIR)/movements.c \
			$(SRC_DIR)/main.c
OUTPUT = so_long

DEBUG_FLAGS = -g -fsanitize=address
LDFLAGS = -L/usr/lib/x86_64-linux-gnu
# Targets
all: $(OUTPUT)

$(OUTPUT): $(LIBFT_LIB) $(MINILIBX_LIB) $(SRC_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(OUTPUT) $(SRC_FILES) $(LIBFT_LIB) $(MINILIBX_LIB) -lm -lX11 -lXext

sanitize: $(LIBFT_LIB) $(MINILIBX_LIB) $(SRC_FILES)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(OUTPUT) $(SRC_FILES) $(LIBFT_LIB) $(MINILIBX_LIB) -lm -lX11 -lXext

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX_LIB):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(LIBFT_LIB) $(MINILIBX_LIB) $(OUTPUT)
	rm -f minilibx-linux/Makefile.gen
	rm -f minilibx-linux/test/Makefile.gen

re: fclean clear all

clear:
	clear

.PHONY: re all clean fclean clear sanitize