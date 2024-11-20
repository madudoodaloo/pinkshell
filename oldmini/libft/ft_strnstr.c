/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:48:59 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/14 18:42:25 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	j = 0;
	i = 0;
	res = (char *)big;
	if (!little[j])
		return (res);
	while ((i < len) && res[i])
	{
		j = 0;
		while (res[i + j] == little[j] && (i + j < len))
		{
			j++;
			if (little[j] == '\0')
				return (&res[i]);
		}
		i++;
	}
	return (NULL);
}
