/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:40:08 by msilva-c          #+#    #+#             */
/*   Updated: 2024/11/22 13:47:36 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../includes/minishell.h"

/* lexer.c */
t_token	*new_token(char *content, int next);
void	add_token(t_token **tokens, char *content, int next);
void	lexer(t_token **tokens, t_token **lst_head);

/* str_utils.c */
char	*strjoinspace(char *s1, char *s2);

#endif
