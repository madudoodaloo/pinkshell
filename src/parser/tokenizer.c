/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:59:01 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/16 23:28:39 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	new->type = -1;
	new->next = NULL;
	new->prev = NULL;
	new->index = -1;
	return (new);
}

t_token	*first_tokens(char **temp)
{
	t_token *head;
	t_token *current;
	int i;

	i = 0;
	head = NULL;
	while (temp[i])
	{
		current = init_token(temp[i]);
		if (!head)
			head = current;
		else
			token_add_back(head, current);
		i++;
	}
	return (head);
}


int tokenizer(t_msh *msh)
{
	char **temp;

	temp = split_spaces(msh->line);
	if (!temp)
		return (-1);
	msh->tokens = first_tokens(temp);
	free_matrix(temp);
	if (!msh->tokens)
		return (-1);


}
