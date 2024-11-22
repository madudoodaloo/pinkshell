/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:44:06 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/17 14:30:59 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	l;

	l = ft_strlen(s);
	i = 0;
	while (i < l)
	{
		f(i, s);
		s++;
		i++;
	}
	*s = '\0';
	return ;
}
