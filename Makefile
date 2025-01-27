# Variables
SRCS = main.c $(wildcard src/*.c) $(wildcard builtins.c/*.c) $(wildcard includes/*.c)
LIBFT_DIR = ft_libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR)
OBJS = $(SRCS:.c=.o)
NAME = minishell

# Rules
all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re