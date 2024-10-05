NAME            =   libftprintf.a
CC              =   cc
CFLAGS          =   -Wall -Wextra -Werror
AR              =   ar
ARFLAGS         =   rcs
RM              =   rm -rf

SRC_DIR         =   ft_printf
OBJ_DIR         =   obj
LIBFT_PATH      =   libft
INCLUDE_DIR     =   include

SRC             =   ft_flush_buffer ft_itoa_base_into_bfr ft_parse_fmt \
                    ft_printf ft_render_char_to_buf ft_render_into_buffer \
                    ft_render_nbrs_to_buf ft_render_str_to_buf \
                    ft_set_pad_spaces_nbr_cases ft_set_pad_zeros_nbr_cases

# Add the .c and .o suffixes for source and object files
SRCS            =   $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))
OBJS            =   $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))

# Libft static library
LIBFT           =   $(LIBFT_PATH)/libft.a

# Targets
all: $(NAME)

# Create object directory if not present
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile ft_printf source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR)

# Combine the libftprintf.a archive from libft.a and ft_printf object files
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: all
	
# Build the Libft library
$(LIBFT):
	make -C $(LIBFT_PATH) all

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

.PHONY: all clean fclean re