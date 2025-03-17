/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:39:20 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/17 21:33:08 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

/* ignore.c */
void	ignore_dollar(char *str);
void	put_dollar_back(char *str);

void	expander(t_token *tokens);

#endif
