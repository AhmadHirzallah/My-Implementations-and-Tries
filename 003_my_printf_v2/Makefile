NAME            =   ./Ft_printf_utils/libftprintf.a
CC              =   cc
CFLAGS          =   -Wall -Wextra -Werror -I
AR              =   ar
ARFLAGS         =   rcs
RM              =   rm -rf
SRC             =   ft_printf	ft_extract_val	ft_fill_buffer	ft_flush_buffer	ft_init_data	ft_pad_buf_wth_n_chrs	ft_parse_flags	ft_parse_fmt	ft_print_chr	ft_print_nbrs	ft_print_str	ft_putstr_buf_n	ft_render_fmt	ft_set_str_pad_spaces
SRCS            =   $(addsuffix .c, $(SRC))
OBJ_DIR         =   ../obj
OBJS            =   $(addprefix $(OBJ_DIR)/, $(SRC:=.o))
LIBFT_PATH      =   ./Libft
LIBFT           =   $(LIBFT_PATH)/libft.a

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
