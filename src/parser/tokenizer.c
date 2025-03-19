/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:59:01 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/19 07:27:06 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


//dar set para null de todas as vars do msh()
int tokenizer(void)
{
	char **matrix;

	matrix = split_spaces(msh()->line);
	if (!matrix)
		return (0);
	msh()->tokens = create_tokens(matrix);
	if (!msh()->tokens)
		return (0);
	free_matrix(matrix);
	re_token(msh()->tokens);
	return (1);
}
