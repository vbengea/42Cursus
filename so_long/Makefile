# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 18:45:23 by vbcvali           #+#    #+#              #
#    Updated: 2024/11/13 19:05:39 by vbcvali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Ilibft -Iminilibx-linux
LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
MINILIBX_MAKEFILE = $(MINILIBX_DIR)/Makefile
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a
SRC_DIR = so_long
SRC_FILES = $(SRC_DIR)/init_map.c \
			$(SRC_DIR)/validate_map.c \
			$(SRC_DIR)/main.c
OUTPUT = main

# Targets
all: $(OUTPUT)

$(OUTPUT): $(LIBFT_LIB) $(MINILIBX_LIB) $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC_FILES) $(LIBFT_LIB) $(MINILIBX_LIB) -lm -lX11 -lXext

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

.PHONY: re all clean fclean clear