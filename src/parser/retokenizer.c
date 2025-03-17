/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retokenizer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:46:51 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/17 13:10:54 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
example:
token->content="ola|"
*/
t_token	*extract_operator(t_token *t)
{
	t_token	*new_t;
	t_token	*next_t;
	char	*help;

	help = ft_substr(t->token, 0, ft_isoperator(t->token, 0));
	new_t = init_token(help);
	free (help);
	help = ft_substr(t->token, ft_isoperator(t->token, 0), ft_strlen(t->token));
	next_t = init_token(help);
	free(help);
	new_t->next = next_t;
	next_t->previous = new_t;
	return (new_t);
}

/*
example:
token->content="ola|"
*/
t_token	*extract_word(t_token *token)
{
	t_token	*new_first;
	t_token	*new_second;
	char	*help;
	int		i;

	i = 0;
	while (ft_isoperator(token->token, i) == 0
		|| (ft_isoperator(token->token, i) > 0 && in_quote(token->token, i)))
		i++;
	help = ft_substr(token->token, 0, i);
	new_first = init_token(help);
	free(help);
	help = ft_substr(token->token, i, ft_strlen(token->token));
	new_second = init_token(help);
	free(help);
	new_first->next = new_second;
	new_first->next->previous = new_first;
	return (new_first);
}


int	needs_retoken(char *cmd)
{
	int i;
	bool operator;
	bool word;

	i = -1;
	while (cmd[++i])
	{
		if (ft_isoperator(cmd, i) && !check_quotes(cmd, i))
			operator = true;
		else
			word = true;
	}
	if (ft_strlen(cmd) > ft_isoperator(cmd, 0) && operator)
		return (2);
	else if (operator && word)
		return (1);
	return (0);
}

t_token *update_token(t_token *old, int flag)
{
	t_token *new;

	if (flag == 0)
		new = old;
	else if (flag == 2 && ft_isoperator(old->content, 0) > 0)
		new = split_operator;
	else
		new = split_word;
	return (new);
}

t_token	*re_token(t_token *head)
{
	t_token *temp;
	int i;

	i = 0;
	temp = head;
	while (temp->next || needs_retoken(temp->content))
	{
		temp = update_token(temp, needs_retoken(temp->content));
		temp = temp->next;
	}
	while (temp->prev)
		temp = temp->prev;
	return (temp);
}
