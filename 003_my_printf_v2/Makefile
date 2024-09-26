NAME            =   libftprintf.a
CC              =   cc
CFLAGS          =   -Wall -Wextra -Werror
AR              =   ar
ARFLAGS         =   rcs
RM              =   rm -rf


SRC_DIR         =   src/Ft_printf_utils
OBJ_DIR         =   ./obj
LIBFT_PATH      =   ./src/Libft


SRC             =   ft_printf ft_extract_val ft_fill_buffer ft_flush_buffer ft_init_data \
                    ft_pad_buf_wth_n_chrs ft_parse_flags ft_parse_fmt ft_print_chr \
                    ft_print_nbrs ft_print_str ft_putstr_buf_n ft_render_fmt \
                    ft_set_str_pad_spaces

# Paths to source and object files
SRCS            =   $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))
OBJS            =   $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))


# Libft static library
LIBFT           =   $(LIBFT_PATH)/libft.a


# Targets
all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile Ft_printf_utils objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build libftprintf.a by combining libft.a and the Ft_printf_utils object files
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Build Libft
$(LIBFT):
	make -C $(LIBFT_PATH) all

# Clean object files and directories
clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

# Full clean (including the libftprintf.a)
fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
