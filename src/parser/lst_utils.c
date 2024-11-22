/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:56:50 by marvin            #+#    #+#             */
/*   Updated: 2024/08/29 11:56:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int     findtype(char *s)
{
    if (!strncmp(s, "echo", ft_strlen(s)) || !strncmp(s, "pwd", ft_strlen(s)) || !strncmp(s, "export", ft_strlen(s)) \
            || !strncmp(s, "cd", ft_strlen(s)) || !strncmp(s, "unset", ft_strlen(s)) || !strncmp(s, "env", ft_strlen(s)))
        return (CMD);
    else if (!strncmp(s, "|", ft_strlen(s)))
        return (PIPE);
    else if (!strncmp(s, ">", ft_strlen(s)) || !strncmp(s, "<", ft_strlen(s)) || !strncmp(s, ">>", ft_strlen(s)) \
            || !strncmp(s, "<<", ft_strlen(s)))
        return (REDIR);
	else if (!strncmp(s, "$", ft_strlen(s)))
		return (ENVVAR);
    return (STR);
}

t_token	*newtoken(char *content)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
    new->type = 0;
	new->next = NULL;
	new->prev = NULL;
	ft_printf("New token: %s$\n", new->content);
	return (new);
}

t_token	*ft_tknlast(t_token *lst)
{
	if (!lst)
	{
		ft_printf("!lst\n");
		return (NULL);
	}
	printf("%p is %s next\n", &lst->next, lst->content);
	lst = lst->next;
	printf("%p is %s next\n", lst->next, lst->content);
	while (lst->next != NULL)
	{
		//printf("%s is content\n", lst->content);
		lst = lst->next;
	}
	ft_printf("%s --- address is %p current->next is %p\n", lst->content, &lst, lst->next);
	return (lst);
}

void	ft_tknadd_back(t_token **lst, t_token *newnode)
{
	if (!*lst)
		*lst = newnode;
	else
		ft_tknlast(*lst)->next = newnode;
}

void	ft_tknclear(t_token **lst)
{
	t_token	*temp;

	while (*lst && (*lst)->next)
	{
		temp = (*lst)->next;
		if ((*lst)->content)
			free((*lst)->content);
		free(*lst);
		*lst = NULL;
		*lst = temp;
	}
	if (*lst)
	{
		if ((*lst)->content)
			free((*lst)->content);
	}
	free(*lst);
	free(lst);
	lst = NULL;
}
