/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:59:04 by msilva-c          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/19 15:13:16 by marianamest      ###   ########.fr       */
=======
/*   Updated: 2025/03/19 15:31:10 by msilva-c         ###   ########.fr       */
>>>>>>> ebc20cefbf185e866de25b0816340fea00465b87
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../includes/minishell.h"

/* create_token.c */
int		get_type(char *str);
void	token_add_back(t_token *head, t_token *new);
t_token	*init_token(char *str);
t_token	*create_tokens(char **temp);

/* envp_1.c */
int		dup_var(t_env *start, t_env *new);
void	var_add_back(t_env *start, t_env *new);
t_env	*create_var(char *str);
int		check_env(char **envp);
t_env	*get_env(char **envp);

/* envp_2.c */
char	**get_default_env(void);
t_env	*empty_env(void);
t_env	*env_dup(t_env *env);

/* init.c */
char	*get_home(void);
t_msh	*msh(void);
t_msh	*init_all(char **envp);

/* parser.c */
int		parser(void);

/* quotes.c */
int		in_quotes(char *line, int max);
int		in_singles(char *line, int max);
int		check_quotes(char *line);

/* retokenizer.c */
t_token	*get_operator(t_token *t);
t_token	*get_word(t_token *t);
int		needs_retoken(char *cmd);
t_token	*get_which(t_token *old);
void	re_token(t_token *head);

/* split_spaces.c */
int		count_words(char *line);
int		parser_wdlen(char *line, int i);
char	**split_spaces(char *line);

/* syntax.c */
int		syntax_red(t_token *token);
int		syntax_pipe(t_token *token);
int		error_redir(t_token *token);
int		error_pipe(void);
int		check_syntax(t_token *token);

/* tokenizer.c */
int		tokenizer(void);

#endif
