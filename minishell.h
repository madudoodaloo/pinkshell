/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:32 by marianamest       #+#    #+#             */
/*   Updated: 2024/11/22 04:37:29 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

/* error handling */
void	print_error(const char *message);

/* cd */
char	*find_env_value(char **env, const char *var);
int		get_current_directory(char *buffer, int size);
void	update_pwd_vars(char **env, const char *old_pwd, const char *new_pwd);
void	change_directory(char **env, const char *path);
void	cd_command(char **env, char **args);

/* env */
char	*create_env_entry(const char *key, const char *value);
char	**allocate_and_init_env_array(char **envp);
int		process_env_variable(char *env_var, char **env, int i);
char	**init_env_array(char **envp);
int		find_env_key_index(char **env, const char *key);
char	**update_env_var(char *arg, char **env, int idx);
char	**expand_env(char **env, char *new_entry);
void	set_or_add_env_value(char ***env, const char *key, const char *value);

/* pwd */
void	my_pwd(int fd);

/* echo */
int		is_flag_n(char *str);
void	print_args(char **args, int start_index);
void	run_echo(char **args);

/* exit */
int		exit_format_error(char *cmd);
int		normalize_exit_code(int code);
void	exit_error(char *arg);
void	exec_exit(char **args);

/* helper functions */
void	my_strcpy(char *dest, const char *src);
void	my_strcat(char *dest, const char *src);

/* madalena */
# define MAXLINE 1024

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
