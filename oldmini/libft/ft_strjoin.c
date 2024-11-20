/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:10:30 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/14 15:17:31 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	newlen;
	size_t	i;
	size_t	j;

	newlen = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(newlen + 1);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s1))
		new[i] = s1[i];
	while (++j < ft_strlen(s2))
		new[i + j] = s2[j];
	new[i + j] = 0;
	return (new);
}
