NAME = minishell
CC = cc

SRC =			src/main/main.c src/parser/env_utils.c src/parser/init.c \
                src/parser/parser.c src/parser/lst_utils.c src/parser/quote_handlers.c \
                src/builtins/cd.c src/builtins/echo.c src/builtins/env1.c src/builtins/env2.c \
                src/builtins/exit.c src/builtins/pwd.c \
				src/builtins/export1.c src/builtins/export2.c \
				src/builtins/unset1.c src/builtins/unset2.c \
                src/utils/utils_builtins.c src/utils/free.c src/utils/heredoc_utils.c\
				src/lexer/lexer.c src/lexer/str_utils.c \
				src/expander/expander.c \
				src/signals/signals1.c src/signals/signals2.c \
				src/heredoc/heredoc1.c src/heredoc/heredoc2.c \
				src/utils/utils_builtins.c src/utils/free.c \
				src/lexer/lexer.c src/lexer/str_utils.c \
				src/expander/expander.c \
				src/executor/execute_builtins.c src/executor/redirections.c src/executor/fork_and_execute1.c\
				src/executor/fork_and_execute2.c 

CFLAGS =		-I./includes -g -fsanitize=address #-Wall -Wextra -Werror
OTHERFLAGS =	-lreadline -lasan -O3

OBJ_DIR =		./obj/
OBJS =			$(patsubst src/%.c, $(OBJ_DIR)%.o, $(SRC))


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(OTHERFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)/*.o
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
