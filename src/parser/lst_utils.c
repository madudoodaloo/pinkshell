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

t_token	*newtoken(char *str, char *content, int start, int wdlen)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
    new->type = -1;
	new->before = '\0';
	printf("start: %d | wdlen is %d\n", start, wdlen);
	if (start)
		new->before = str[start - 1];
	new->after = '\0';
	printf("strlen is %zu\n", ft_strlen(str));
	if (wdlen < ft_strlen(str))
		new->after = str[wdlen + 1];
	new->next = NULL;
	return (new);
}

t_token *tokenize(char *str, int start, int wdlen)
{
    t_token *a;

    char *substring = substr_new(str, start, wdlen);
    a = newtoken(str, substring, start, wdlen);
    return (a);
}

t_token	*ft_tknlast(t_token *lst)
{
	if (!lst)
	{
		ft_printf("!lst\n");
		return (NULL);
	}
	//printf("%p is %s next\n", &lst->next, lst->content);
	//printf("%p is %s next\n", lst->next, lst->content);
	while (lst->next != NULL)
	{
		//printf("%s is content\n", lst->content);
		lst = lst->next;
	}
	ft_printf("lst->content is %s\n", lst->content);
	ft_printf("lst->next is %p\n", lst->next);
	//ft_printf("%s --- address is %p current->next is %p\n", lst->content, &lst, lst->next);
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

	if (!*lst)
		return ;
    while (lst && *lst)
    {
        temp = (*lst)->next;
        if ((*lst)->content)
            free((*lst)->content);
        free(*lst);
        *lst = temp;
    }
}
