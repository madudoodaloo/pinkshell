/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:21:38 by msilva-c          #+#    #+#             */
/*   Updated: 2024/11/22 16:04:00 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*new_token(char *content, int next)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
	new->type = CMD;
	new->before = '\0';
	new->after = next;
	new->next = NULL;
	return (new);
}

void	add_token(t_token **tokens, char *content, int next)
{
	t_token	*new;
	t_token	*last;

	new = new_token(content, next);
	if (!new)
		return ;
	printf("*tokens is %p\n", *tokens);
	if (!*tokens)
	{
		*tokens = new;
		printf("!*tokens\n");
		return ;
	}
	printf("is here\n");
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
	if (!old->next)
	{
		add_token(tokens, old->content, '\0');
		return ;
	}
	while (old)
	{
		str = ft_strdup(old->content);
		printf("str is %s\n", str);
		printf("old->type is %d\n", old->type);
		printf("old->next->type is %d\n", old->next->type);
		printf("bool 1 %d || bool 2 %d\n", old->type == STR, old->next->type == STR);

		while (old && old->next && old->type == STR && old->next->type == STR)
		{
			printf("temp is %p\n", temp);
			temp = strjoinspace(str, old->next->content);
			if (!temp)
			{
				printf("!temp\n");
				return ;
			}
			free(str);
			str = temp;
			//printf("str is %s\n", str);
			old = old->next;
		}
		printf("bool is %d\n", old->after == '\0');
		if (old->after == '\0')
		{
			add_token(tokens, str, '\0');
			return ;
		}
		else if (old->next->type == PIPE || old->next->type == REDIR)
			add_token(tokens, str, old->next->type);
		old = old->next;
	}
	free_struct(lst_head);
}
