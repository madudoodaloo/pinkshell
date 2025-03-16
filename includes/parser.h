/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:59:04 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/16 22:00:18 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2025/03/08 15:09:55 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../includes/minishell.h"


/* tokenizer */



/* quotes.c */
int in_quotes(char *line, int i);
int check_quotes(char *line, int max);


/* parser.c */
int	parser(t_msh *msh);

#endif
