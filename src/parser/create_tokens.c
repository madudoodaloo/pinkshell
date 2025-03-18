/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:24:05 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 02:10:05 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h""../includes/minishell.h"

int get_type(char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(str, ">") == 0)
		return (R_OUT);
	if (ft_strcmp(str, ">>") == 0)
		return (R_APP);
	else if (ft_strcmp(str, "<") == 0)
		return (R_IN);
	else if (ft_strcmp(str, "<<") == 0)
		return (HERE_DOC);
	else
		return (CMD);
}

void	token_add_back(t_token *head, t_token *new)
{
	t_token *current;

	current = head;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
}


t_token	*init_token(char *str)
{
	t_token *new;

	new = (t_token *)safe_malloc(sizeof(t_token));
	new->content = ft_strdup(str);
	if (!new || !new->content)
		return (NULL);
	new->type = get_type(str);
	new->next = NULL;
	new->prev = NULL;
	new->index = -1;
	return (new);
}

t_token	*create_tokens(char **temp)
{
	t_token *head;
	t_token *current;
	int i;

	i = 0;
	head = NULL;
	while (temp[i])
	{
		current = init_token(temp[i]);
		if (!current)
			return (head);
		current->index = i;
		if (!head)
			head = current;
		else
			token_add_back(head, current);
		i++;
	}
	return (head);
}
