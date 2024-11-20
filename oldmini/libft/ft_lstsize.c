/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:09:42 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/19 19:28:05 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		i++;
		lst = (*lst).next;
	}
	return (i);
}
