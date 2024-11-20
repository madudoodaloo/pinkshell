#.SILENT:
NAME = minishell
CC = cc

#libs
SRC_PATH =		./src/
SRC_FILES =		env_utils.c free.c init.c lexer.c lst_utils.c main.c
SRC =			$(addprefix $(SRC_PATH), $(SRC_FILES))

LIBFT_PATH =	./libft/
LIBFT =			$(LIBFT_PATH)libft.a

CFLAGS =		-g -fsanitize=address #-Wall -Wextra -Werror
OTHERFLAGS =	-L$(LIBFT_PATH) -lft -lreadline -lasan -O3

OBJ_DIR =		./obj/
OBJS =			$(SRC:$(SRC_PATH)%.c=$(OBJ_DIR)%.o)

#rules
all: $(NAME)

$(NAME): $(OBJS)
	@make -sC libft/
	@$(CC) $(CFLAGS) $(OBJS) $(OTHERFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)/*
	@rm -fd obj/
	@make clean -sC libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC libft/

re: fclean all

.PHONY: all clean fclean re
