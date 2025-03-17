/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retokenizer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:46:51 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/17 13:35:11 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * example:
 * token->content="ola|"
 */
t_token	*get_operator(t_token *t)
{
	char	*temp;
	t_token	*op;
	t_token	*remain;

	temp = ft_substr(t->content, 0, ft_isoperator(t->content, 0));
	op = init_token(temp);
	free (temp);
	temp = ft_strdup(t->content[ft_isoperator(t->content, 0)]);
	remain = init_token(temp);
	free(temp);
	remain->prev = op;
	op->next = remain;
	return (op);
}

/*
 * example:
 * token->content="ola|"
*/
t_token	*get_word(t_token *t)
{
	int		i;
	char	*temp;
	t_token	*word;
	t_token	*remain;

	i = 0;
	while ((ft_isoperator(t->content, i) > 0 && in_quote(t->content, i)) || ft_isoperator(t->content, i) == 0)
		i++;
	temp = ft_substr(t->content, 0, i);
	word = init_token(temp);
	free(temp);
	temp = ft_strdup(t->content[i]);
	remain = init_token(temp);
	free(temp);
	word->next = remain;
	word->next->prev = word;
	return (word);
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
		new = get_operator(old);
	else
		new = get_word(old);
	return (new);
}

t_token	*re_token(t_token *head)
{
	t_token *temp;
	int i;

	i = 0;
	temp = head;
	while (temp)
	{
		temp = update_token(temp, needs_retoken(temp->content));
		temp = temp->next;
	}
	while (temp->prev)
		temp = temp->prev;
	return (temp);
}
