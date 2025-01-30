/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:40:30 by msilva-c          #+#    #+#             */
/*   Updated: 2024/12/05 15:55:36 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int check_expand(t_token *token)
{
	if (count_quotes(token->content, 0))
		return 0;
}

void	expander(t_token *tokens, char **env)
{
	t_token	*node;
	char *line;

	node = tokens;
	line = NULL;
	while (node)
	{
		//if (node->type == 1 && check_expand(node))
			//switch_value(node, env);
		return ;
	}
}
