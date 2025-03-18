/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:59:04 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 02:07:44 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../includes/minishell.h"

/* create_token.c */
int get_type(char *str);
void	token_add_back(t_token *head, t_token *new);
t_token	*init_token(char *str);
t_token	*create_tokens(char **temp);

/* env.c */
int dup_var(t_env *start, t_env *new);
void    var_add_back(t_env *start, t_env *new);
t_env   *create_var(char *str);
char    **get_default_env(void);
t_env   *empty_env(void);
int     check_env(char **envp);
t_env   *get_env(char **envp);
t_env   *env_dup(t_env *env);

/* init.c */
char    *get_home(void);
t_msh   *msh(void);
t_msh   *init_all(char **envp);

/* parser.c */
int		parser(t_msh *msh);

/* quotes.c */
int 	check_singles(char *line, int max);
int		check_quotes(char *line, int max);

/* retokenizer.c */
t_token	*get_operator(t_token *t);
t_token	*get_word(t_token *token);
t_token	*update_token(t_token *old, int flag);
int		needs_retoken(char *cmd);
t_token	*re_token(t_token *head);

/* split_spaces.c */
int		count_words(char *line);
int		parser_wdlen(char *line, int i);
char	**split_spaces(char *line);

/* tokenizer.c */
int		tokenizer(t_msh *msh);


#endif
