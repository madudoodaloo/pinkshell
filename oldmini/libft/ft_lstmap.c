/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:16:31 by skioridi          #+#    #+#             */
/*   Updated: 2023/05/02 18:00:50 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	new = NULL;
	while (lst)
	{
		node = ft_lstnew(f((*lst).content));
		if (!node)
		{
			ft_lstdelone(node, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
