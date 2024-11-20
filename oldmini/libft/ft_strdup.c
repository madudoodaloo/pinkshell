/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:12:25 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/14 13:32:05 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (i <= (ft_strlen(s)))
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}
