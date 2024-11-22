/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:22 by skioridr          #+#    #+#             */
/*   Updated: 2023/05/23 18:26:20 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			r;

	line = NULL;
	r = 1;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		r = -1;
		if (fd >= 0 && fd <= FOPEN_MAX)
			while (buffer[fd][++r])
				buffer[fd][r] = 0;
		return (NULL);
	}
	while (r > 0)
	{
		if (!buffer[fd][0])
			r = read(fd, buffer[fd], BUFFER_SIZE);
		if (r > 0)
			line = ft_join_nl(line, buffer[fd]);
		if (nlcheck(buffer[fd]))
			break ;
	}
	return (line);
}
