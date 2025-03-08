/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:06:48 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/08 02:34:00 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = s;
	while (i < n)
	{
		*ptr = c;
		i++;
		ptr++;
	}
	return (s);
}

void *safe_malloc(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
	{
		ft_put_str_fd("Failed malloc\n", 2);
		clean_all();
		exit(1); //rever
	}
	ft_memset(new, '\0', size);
	return (new);
}
