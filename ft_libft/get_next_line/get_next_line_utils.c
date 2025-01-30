/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:25 by skioridi          #+#    #+#             */
/*   Updated: 2024/03/06 13:26:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_join_nl(char *line, char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!line)
	{
		line = (char *)malloc(sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buffer)
		return (NULL);
	new = (char *)malloc(ft_strlen_nl(line) + ft_strlen_nl(buffer) + 1);
	if (!new)
		return (NULL);
	i = -1;
	j = 0;
	if (line)
	{
		while (line[++i] != '\0')
			new[i] = line[i];	
	}
	while (buffer[j])
		new[i++] = buffer[j++];
	new[ft_strlen_nl(line) + ft_strlen_nl(buffer)] = '\0';
	free(line);
	return (new);
}

int	nlcheck(char *buffer)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		buffer[i++] = '\0';
	if (buffer[i] == '\n')
	{
		found = 1;
		buffer[i++] = '\0';
		while (buffer[i])
		{
			buffer[j++] = buffer[i];
			buffer[i++] = '\0';
		}
	}
	return (found);
}
