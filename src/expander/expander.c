/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:40:30 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/01 16:59:03 by marianamest      ###   ########.fr       */
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
