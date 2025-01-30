/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:25:39 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/13 17:28:33 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*t1;
	unsigned const char	*t2;

	i = 0;
	t1 = dest;
	t2 = src;
	if (t1 == NULL && t2 == NULL)
		return (NULL);
	while (i < n)
	{
		t1[i] = t2[i];
		i++;
	}
	return (t1);
}
