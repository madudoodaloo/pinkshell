/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:21:38 by msilva-c          #+#    #+#             */
/*   Updated: 2024/12/03 01:13:52 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*new_token(char *content, int next)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	free(content);
	new->type = CMD;
	new->before = '\0';
	new->after = next;
	new->next = NULL;
	return (new);
}

void	add_token(t_token **tokens, char *content, t_token *lst_head)
{
	t_token	*new;
	t_token	*last;
	int		next_cmd;

	printf("entered add_token\n");
	if (!lst_head->next)
		next_cmd = '\0';
	else
		next_cmd = lst_head->next->type;
	new = new_token(content, next_cmd);
	if (!new)
		return ;
	printf("*tokens is %p\n", *tokens);
	if (!*tokens)
	{
		*tokens = new;
		printf("created head of tokens\n");
		return ;
	}
	last = ft_tknlast(*tokens);
	last->next = new;
	return ;
}

void	lexer(t_token **tokens, t_token **lst_head)
{
	t_token	*old;
	char	*str = NULL;
	char *temp = NULL;
	old = *lst_head;
	printf("entered lexer\n");
	while (old)
	{
		str = ft_strdup(old->content);
		if (old->type == STR)
		{
			while (old && old->next && old->type == STR && old->next->type == STR)
			{
				temp = strjoinspace(str, old->next->content);
				if (!temp)
					printf("error occured in strjoinspace\n");
				free(str);
				str = temp;
				old = old->next;
			}
			add_token(tokens, str, old);
		}
		else if (old && (old->type == PIPE || old->type == REDIR))
			add_token(tokens, str, old);
		else if (!old)
			return ;
		old = old->next;
	}
	free_struct(lst_head);
}
