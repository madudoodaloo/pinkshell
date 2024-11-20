/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:25 by skioridi          #+#    #+#             */
/*   Updated: 2024/02/28 16:46:51 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*ft_join_nl(char *line, char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = (char *)malloc(ft_strlen_nl(line) + ft_strlen_nl(buffer) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (line && line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	while (buffer && buffer[j] && buffer[j] != '\n')
		new[i++] = buffer[j++];
	if (buffer[j] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
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
