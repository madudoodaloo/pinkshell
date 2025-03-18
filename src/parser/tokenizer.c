/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:59:01 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/17 23:21:06 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int tokenizer(t_msh *msh)
{
	char **matrix;

	matrix = split_spaces(msh->line);
	if (!matrix)
		return (-1);
	msh->tokens = create_tokens(matrix);
	if (!msh->tokens)
		return (-1);
	free_matrix(matrix);
	msh->tokens = re_token(msh->tokens);


}
