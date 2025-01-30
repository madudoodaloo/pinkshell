NAME = minishell
CC = cc

SRC =			src/main/main.c src/parser/env_utils.c src/parser/init.c \
                src/parser/parser.c src/parser/lst_utils.c src/parser/quote_handlers.c \
                src/builtins/cd.c src/builtins/echo.c src/builtins/env1.c src/builtins/env2.c \
                src/builtins/exit.c src/builtins/pwd.c \
                src/utils/utils_builtins.c src/utils/free.c \
				src/lexer/lexer.c src/lexer/str_utils.c \
				src/expander/expander.c \
				src/signals/signals1.c src/signals/signals2.c 

LIBFT_PATH=		./ft_libft/
LIBFT=			$(LIBFT_PATH)libft.a

CFLAGS =		-I./includes -g -fsanitize=address #-Wall -Wextra -Werror
OTHERFLAGS =	-L$(LIBFT_PATH) -lft -lreadline -lasan -O3

OBJ_DIR =		./obj/
OBJS =			$(patsubst src/%.c, $(OBJ_DIR)%.o, $(SRC))


#rules
all: $(NAME)

$(NAME): $(OBJS)
	@make -sC $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(OTHERFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)/*.o
	@rm -rf $(OBJ_DIR)
	@make clean -sC ft_libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC ft_libft/

re: fclean all

.PHONY: all clean fclean re
