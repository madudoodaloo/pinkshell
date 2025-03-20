NAME = minishell
CC = cc

SRC =			src/1_main/main.c \
				src/2_parser/create_tokens.c \
				src/2_parser/envp_1.c \
				src/2_parser/envp_2.c \
				src/2_parser/init_exec.c \
				src/2_parser/init.c \
				src/2_parser/parser.c \
				src/2_parser/quotes.c \
				src/2_parser/retokenizer.c \
				src/2_parser/split_spaces.c \
				src/2_parser/syntax.c \
				src/2_parser/tokenizer.c \
				src/3_expander/expander_1.c \
                src/3_expander/expander_2.c \
                src/3_expander/expander_3.c \
				src/signals/signals.c \
				src/utils/free_1.c \
                src/utils/free_2.c \
                src/utils/libft_utils1.c \
                src/utils/libft_utils2.c \
                src/utils/libft_utils3.c \
                src/utils/libft_utils4.c \
                src/utils/libft_utils5.c \
                src/utils/malloc.c \
                src/utils/utils_str.c \
				src/utils/delete.c

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
