/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:40:08 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/16 20:13:25 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

/* lexer.c */
t_token	*new_token(char *content, int next);
void	add_token(t_token **tokens, char *content, t_token *lst_head);
void	lexer(t_token **tokens, t_token **lst_head);

/* str_utils.c */
char	*strjoinspace(char *s1, char *s2);

#endif
