/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabrito- <mabrito-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:11 by mabrito-          #+#    #+#             */
/*   Updated: 2023/11/10 15:59:00 by mabrito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlist;

	if (lst == NULL)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newnode = (t_list *)malloc(sizeof(t_list)); //allocates memory for new node
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		newnode->content = f(lst->content); //calls f function to move the content of the current node to the new one;
		newnode->next = NULL; //and points it to null
		ft_lstadd_back(&newlist, newnode); //add the newly created node to the end of the new list
		lst = lst->next; //moves on to the next node in the og list
	}
	return (newlist); //returns the new list (mapping of the og one)
}
