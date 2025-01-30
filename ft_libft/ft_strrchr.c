/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:38:51 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/13 18:48:47 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return ((char *)&s[i]);
		i--;
	}
	if ((unsigned char)c == 0)
		return ((char *)&s[ft_strlen(s)]);
	return (NULL);
}
