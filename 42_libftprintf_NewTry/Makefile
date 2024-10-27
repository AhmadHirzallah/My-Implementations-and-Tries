# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 12:42:49 by aulicna           #+#    #+#              #
#    Updated: 2023/05/01 17:16:26 by aulicna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXEC = my_program

SRC = 	ft_printf.c \
	format_char.c \
	format_str.c \
	format_dec_int.c \
	format_dec_int_2.c \
	format_unsigned.c \
	format_unsigned_2.c \
	format_hex.c \
	format_hex_zero.c \
	format_pointer_hex.c \
	format_decision.c \
	process_flags.c \
	count_digits.c \
	loop_print.c \
	main.c

OBJ = $(SRC:.c=.o)

LIBFT = libft

CFLAGS = -Wall -Werror -Wextra -g

GCC = cc

AR = ar rcs


all: $(NAME) $(EXEC)


bonus: all

${NAME}: $(OBJ)
	make -C $(LIBFT) bonus
	cp libft/libft.a ./
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

$(EXEC): $(OBJ)
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ) -L. -lftprintf

.c.o:
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	@rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	@rm -f $(NAME)

.PHONY: all clean fclean re
