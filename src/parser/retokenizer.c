/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retokenizer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:46:51 by msilva-c          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/19 11:50:07 by marianamest      ###   ########.fr       */
=======
/*   Updated: 2025/03/19 10:13:26 by msilva-c         ###   ########.fr       */
>>>>>>> 17c155bfb08a62142f68f6adc0b968a84a8443f4
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * example:
 * token->content=">>test.txt|cat"
 */
t_token	*get_operator(t_token *t)
{
	char	*temp;
	t_token	*op;
	t_token	*remain;

	temp = ft_substr(t->content, 0, ft_isoperator(t->content, 0));
	op = init_token(temp);
	free(temp);
	temp = ft_substr(t->content, ft_isoperator(t->content, 0),
			ft_strlen(t->content));
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
	while (t->content[i] && ((ft_isoperator(t->content, i) > 0
				&& in_quotes(t->content, i)) || ft_isoperator(t->content,
				i) == 0))
		i++;
	temp = ft_substr(t->content, 0, i);
	word = init_token(temp);
	free(temp);
	temp = ft_substr(t->content, i, ft_strlen(t->content));
	remain = init_token(temp);
	free(temp);
	word->next = remain;
	word->next->prev = word;
	return (word);
}

int	needs_retoken(char *cmd)
{
	int		i;
	bool	operator;
	bool	word;

	i = -1;
	while (cmd[++i])
	{
		if (ft_isoperator(cmd, i) && !in_quotes(cmd, i))
			operator= true;
		else
			word = true;
	}
	if (ft_strlen(cmd) > ft_isoperator(cmd, 0) && operator)
		return (2);
	else if (operator&& word)
		return (1);
	return (0);
}

t_token	*update_token(t_token *old, int flag)
{
	t_token	*new;

	if (flag == 0)
		new = old;
	else if (flag == 2 && ft_isoperator(old->content, 0) > 0)
		new = get_operator(old);
	else
		new = get_word(old);
	return (new);
}

void	re_token(t_token *head)
{
	t_token	*temp;

	temp = head;
	while (temp)
	{
        printf("  Token content: %s\n", temp->content ? temp->content : "(NULL)");
        printf("  needs_retoken: %s\n", needs_retoken(temp->content));
		temp = update_token(temp, needs_retoken(temp->content));
		temp = temp->next;
	}
	return ;
}
