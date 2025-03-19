NAME = minishell
CC = cc

SRC =			src/main/main.c \
				src/utils/free_1.c \
                src/utils/free_2.c \
                src/utils/heredoc_utils.c \
                src/utils/libft_utils1.c \
                src/utils/libft_utils2.c \
                src/utils/libft_utils3.c \
                src/utils/libft_utils4.c \
                src/utils/libft_utils5.c \
                src/utils/malloc.c \
                src/utils/utils_builtins.c \
                src/utils/utils_str.c \
				src/parser/create_tokens.c \
				src/parser/envp_1.c \
				src/parser/envp_2.c \
				src/parser/init.c \
				src/parser/parser.c \
				src/parser/quotes.c \
				src/parser/retokenizer.c \
				src/parser/split_spaces.c \
				src/parser/syntax.c \
				src/parser/tokenizer.c \
				src/expander/expander_1.c \
                src/expander/expander_2.c \
                src/expander/expander_3.c \
				src/executor/init_exec.c
#src/executor/execute_builtins.c 				src/executor/redirections1.c 				src/executor/fork_and_execute1.c 				src/executor/fork_and_execute2.c 				src/executor/exec_parser.c 				src/executor/redirections2.c 				src/builtins/cd.c 				src/builtins/echo.c 				src/builtins/env1.c 				src/builtins/env2.c 				src/builtins/exit.c 				src/builtins/pwd.c 				src/builtins/export1.c 				src/builtins/export2.c 				src/builtins/unset1.c 				src/builtins/unset2.c 				src/heredoc/heredoc1.c 				src/heredoc/heredoc2.c 				src/signals/signals1.c 				src/signals/signals2.c \

CFLAGS =		-I./includes -g #-fsanitize=address -Wall -Wextra -Werror
OTHERFLAGS =	-lreadline #-lasan -O3

OBJ_DIR =		./obj/
OBJS =			$(patsubst src/%.c, $(OBJ_DIR)%.o, $(SRC))


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(OTHERFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
