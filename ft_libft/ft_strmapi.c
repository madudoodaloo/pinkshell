/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:43:50 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/17 14:23:44 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	i = ft_strlen(s);
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	new[i] = '\0';
	i--;
	while (i >= 0)
	{
		new[i] = f(i, s[i]);
		i--;
	}
	return (new);
}
