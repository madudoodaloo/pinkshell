/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:59:01 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 01:20:01 by msilva-c         ###   ########.fr       */
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
	t_token *temp = msh->tokens;
	while (temp)
	{
		printf("token[%d]: %s\n", temp->index, temp->content);
		temp = temp->next;
	}
}
