/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:04:49 by msilva-c          #+#    #+#             */
/*   Updated: 2024/12/02 23:58:28 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*strjoinspace(char *s1, char *s2)
{
	char	*new;
	size_t	newlen;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
	{
		printf("s1 or s2 is NULL\n");
		return (NULL);
	}
	printf("s1 is %s\n", s1);
	printf("s2 is %s\n", s2);
	newlen = ft_strlen(s1) + ft_strlen(s2);
	printf("newlen + 2 = %ld\n", newlen + 2);
	new = malloc(newlen + 2);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
	{
		new[i] = s1[i];
		printf("new[%zu] is %c\n", i, new[i]);
	}
	new[i] = ' ';
	printf("new[%zu] is %c\n", i, new[i]);
	i++;
	while (s2[++j])
	{
		new[i + j] = s2[j];
		printf("new[%zu] is %c\n", i + j, new[i + j]);
	}
	new[i + j] = '\0';
	printf("new is %s$\n", new);
	return (new);
}
