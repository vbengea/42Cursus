# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbengea < vbengea@student.42madrid.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 17:45:15 by vbcvali           #+#    #+#              #
#    Updated: 2025/01/23 12:46:46 by vbengea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast_libft.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_printf_utils.c \
		ft_printf.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_strndup.c \
		ft_isspace.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

cc = cc

AR = ar rcs
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating library $(NAME)"
	@$(AR) $(NAME) $(OBJS)

clean:
	@echo "Cleaning object files"
	@$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning all generated files"
	@$(RM) $(NAME)

re :fclean clear all

clear:
	clear

.PHONY: all clean fclean re clear
