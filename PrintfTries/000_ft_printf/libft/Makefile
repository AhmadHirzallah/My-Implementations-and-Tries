SRCS        = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c

B_SRCS      = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS_DIR    = obj

OBJS        = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
B_OBJS      = $(addprefix $(OBJS_DIR)/, $(B_SRCS:.c=.o))

NAME        = libft.a

CC          = cc

RM          = rm -rf

AR          = ar rcs

CFLAGS      = -Wall -Wextra -Werror

# Create the directory for object files if it doesn't exist
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Compile the object files and place them in the obj directory
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	${CC} ${CFLAGS} -c $< -o $@ -I../include

# Build the library
$(NAME): $(OBJS)
	${AR} ${NAME} ${OBJS}

all: $(NAME)

# Handle bonus
bonus: $(B_OBJS) $(NAME)
	${AR} ${NAME} ${B_OBJS}

# Clean object files and remove the obj directory
clean:
	${RM} $(OBJS_DIR)

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re