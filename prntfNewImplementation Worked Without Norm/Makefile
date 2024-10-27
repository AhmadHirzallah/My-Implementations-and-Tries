# Variables
NAME = libftprintf.a
EXEC = my_program

# Source files (add all your source files here)
SRC = 	ft_printf.c \
		format_chr_str.c \
		ft_printf_utils.c \
		parsing_flags_specifier.c \
		rendering_fmt.c \
		main.c \
		format_nbrs.c

# Object files (will be automatically generated from SRC)
OBJ = $(SRC:.c=.o)

# Path to libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g # Added -g for debugging

# Archive (for creating static libraries)
AR = ar rcs

# Targets
all: $(NAME) $(EXEC)

# Creating the libftprintf.a library from object files and linking with libft
$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) # Compile libft
	cp $(LIBFT) ./
	mv libft.a $(NAME)        # Rename libft.a to libftprintf.a
	$(AR) $(NAME) $(OBJ)

# Creating the executable by linking the object files and the static library
$(EXEC): $(OBJ) $(NAME)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -L. -lftprintf

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Execute rule for debugging with gdb
execute: $(EXEC)
	gdb ./$(EXEC)

# Cleaning object files in your project
clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR) # Clean libft object files

# Cleaning all generated files, including the static library and executable
fclean: clean
	@rm -f $(NAME)
	@rm -f $(EXEC)
	@$(MAKE) fclean -C $(LIBFT_DIR) # Full clean of libft

# Recompiling everything from scratch
re: fclean all

.PHONY: all clean fclean re execute