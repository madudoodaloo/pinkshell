/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:59:04 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/08 01:39:36 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../includes/minishell.h"

/* env_utils.c */
char **copy_matrix(char **src);

/* init.c */
t_msh	*msh(void);
t_msh    *init_all(t_msh *msh);

/* parser.c */
int     findtype(char *s, int flag);
t_token *tokenize(char *str, int start, int wdlen);
int add_node(t_token **lst_head, char *line, int i, int j);
int strchr_wdlen(const char *s, int c);
void split_cmds(char *line, int i, int j, t_token **lst_head);
void	parser(char *cmdline, t_token **lst_head);

/* quote_handler.c */
int	quote_handler(char *cmdline, int i, t_token **lst_head);
int count_quotes(char *line, int i);

/* lst_utils.c */
char	*substr_new(char const *s, unsigned int start, size_t len);
void	ft_tknclear(t_token **lst);
t_token	*newtoken(char *str, char *content, int start, int wdlen);
t_token	*ft_tknlast(t_token *lst);
void	ft_tknadd_back(t_token **lst, t_token *newnode);

#endif
