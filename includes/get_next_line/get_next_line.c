/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:22 by skioridi          #+#    #+#             */
/*   Updated: 2024/02/28 16:50:51 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_memset(char *buffer)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			r;

	ft_memset(buffer);
	line = NULL;
	r = 1;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		r = -1;
		while (buffer[++r])
			buffer[r] = 0;
		return (NULL);
	}
	while (r > 0)
	{
		if (!buffer[0])
			r = read(fd, buffer, BUFFER_SIZE);
		if (r > 0)
			line = ft_join_nl(line, buffer);
		if (nlcheck(buffer))
			break ;
	}
	return (line);
}
