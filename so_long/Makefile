# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Libraries
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

# Source files
SRCS = main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
NAME = my_program

# Rule to compile the libraries
$(LIBFT):
	make -C ./libft

$(MINILIBX):
	make -C ./minilibx-linux

# Rule to compile the executable
$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX) -lX11 -lXext
	@echo "Executable $(NAME) created."

# Rule to compile the object files
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the object files
clean:
	rm -f $(OBJS)
	make -C ./libft clean
	make -C ./minilibx-linux clean

# Rule to clean the object files and the executable
fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
	make -C ./minilibx-linux clean

# Rule to recompile everything
re: fclean $(NAME)

# Default rule
all: $(NAME)

.PHONY: all clean fclean re