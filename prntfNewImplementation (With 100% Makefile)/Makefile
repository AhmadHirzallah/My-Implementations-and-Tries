# Variables
NAME            = libftprintf.a
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -I$(INCLUDE_DIR)
AR              = ar
ARFLAGS         = rcs
RM              = rm -rf

# Directories
SRC_DIR         = .
OBJ_DIR         = obj
LIBFT_PATH      = libft
INCLUDE_DIR     = include

# Source files (add all your source files here without .c suffix)
SRC             = ft_printf \
                  format_chr_str \
                  ft_printf_utils \
                  parsing_flags_specifier \
                  format_nbrs \
                  format_helpers

# Add the .c and .o suffixes for source and object files
SRCS            = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))
OBJS            = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))

# Libft static library
LIBFT           = $(LIBFT_PATH)/libft.a

# Targets
all: $(NAME)

# Create object directory if not present
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile source files into object files and place them in obj directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Combine the libftprintf.a archive from libft.a and object files
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Build the Libft library
$(LIBFT):
	make -C $(LIBFT_PATH) all

# Handle the bonus target (same as 'all' in this case)
bonus: all

# Clean the object files and directories
clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

# Full clean, including the archive file
fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re bonus