/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:59:04 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/16 23:24:44 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2025/03/08 15:09:55 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../includes/minishell.h"

/* split_spaces.c */
int count_words(char *line);
int parser_wdlen(char *line, int i);
char **split_spaces(char *line);

/* tokenizer.c */
void	token_add_back(t_token *head, t_token *new);
t_token	*init_token(char *str);
t_token	*first_tokens(char **temp);
int tokenizer(t_msh *msh);


/* quotes.c */
int in_quotes(char *line, int i);
int check_quotes(char *line, int max);


/* parser.c */
int	parser(t_msh *msh);

#endif
