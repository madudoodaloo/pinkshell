/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:50:42 by skioridi          #+#    #+#             */
/*   Updated: 2024/09/18 18:48:39 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

#define MAXLINE 1024

typedef struct s_token
{
	char		*content;
	int 		type;
	struct s_token	*next;
	struct s_token	*prev;
}			t_token;

typedef struct s_msh
{
	char		*line;
	int		exit;
	int		ret;
	t_token **lst_head;
	char **env;
}			t_msh;

// types for node struct
#define CMD 1
#define PIPE 2
#define REDIR 3
#define QUOTE 4
#define ENVVAR 5
#define STR 6

/* env_utils.c */
char **copy_matrix(char **src);

/* init.c */
t_msh    *init_all(t_msh *msh);

/* free.c */
void   free_and_exit(t_msh *msh);
void	ft_free_matrix(char **matrix);

/* lexer.c */
int     findtype(char *s);
t_token *tokenize(char *str, int start, int wdlen);
int add_node(t_token **lst_head, char *line, int i, int j);
int strchr_wdlen(const char *s, int c);
void split_cmds(char *line, int i, int j, t_token **lst_head);
void new_lexer(char *cmdline, t_token **lst_head);
void	final_lexer(char *cmdline, t_token **lst_head);

/* lst_utils.c */
char	*substr_new(char const *s, unsigned int start, size_t len);
void	ft_tknclear(t_token **lst);
t_token	*newtoken(char *content);
t_token	*ft_tknlast(t_token *lst);
void	ft_tknadd_back(t_token **lst, t_token *newnode);
int	quote_handler(char *cmdline, int i, t_token **lst_head);

#endif
