/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:38:58 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/14 15:26:12 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	cp_len;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		cp_len = 0;
	else if (start + len >= ft_strlen(s))
		cp_len = ft_strlen(s) - start;
	else
		cp_len = len;
	new = (char *)malloc(cp_len + 1);
	if (!new)
		return (NULL);
	i = -1;
	while ((++i < cp_len))
		new[i] = (char)s[start + i];
	new[i] = 0;
	return (new);
}
