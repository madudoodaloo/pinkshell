/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:40:30 by msilva-c          #+#    #+#             */
/*   Updated: 2024/12/05 12:20:23 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	expander(t_token *tokens, char **env)
{
	t_token	*node;
	char *line;

	node = tokens;
	line = NULL;
	while (node)
	{
		printf("type of the node is %s\n", node->type);
		node = node->next;
		//line = node->content;
	}
}
