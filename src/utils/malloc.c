/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:19:22 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/19 05:04:08 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n--)
	{
		*str = c;
		str++;
	}
	return (s);
}

void	*safe_malloc(size_t size)
{
	void	*new;

	new = NULL;
	new = (void *)malloc(size);
	if (!new)
	{
		ft_put_str_fd("Failed malloc\n", 2);
		free_and_exit(); // rever
		exit(1); // rever
	}
	ft_memset(new, '\0', size);
	return (new);
}
