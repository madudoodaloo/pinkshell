/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:59:01 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 17:38:04 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int tokenizer(t_msh *msh)
{
	char **matrix;

	matrix = split_spaces(msh->line);
	if (!matrix)
		return (0);
	msh->tokens = create_tokens(matrix);
	if (!msh->tokens)
		return (0);
	free_matrix(matrix);
	msh->tokens = re_token(msh->tokens);
	return (1);
}
