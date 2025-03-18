/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:35:37 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 18:44:50 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int in_quotes(char *line, int max)
{
	int i;
	int singleq;
	int doubleq;

	i = 0;
	singleq = 0;
	doubleq = 0;
	if (!line)
		return (0);
	while (line[i] && i < max)
	{
		if (line[i] == 39 && doubleq % 2 == 0)
			singleq += 1;
		else if (line[i] == 34 && singleq % 2 == 0)
			doubleq += 1;
		i++;
	}
	if (singleq % 2 == 0 && doubleq % 2 == 0)
		return (0);
	return (1);
}

int in_singles(char *line, int max)
{
	int i;
	int singleq;
	int doubleq;

	i = 0;
	singleq = 0;
	doubleq = 0;
	if (!line)
		return (0);
	while (line[i] && i < max)
	{
		if (line[i] == 39 && doubleq % 2 == 0)
			singleq += 1;
		else if (line[i] == 34 && singleq % 2 == 0)
			doubleq += 1;
		i++;
	}
	if (singleq % 2 == 1 && doubleq % 2 == 0)
		return (1);
	return (0);
}
/* checks if the given input has valid quotes
 * open quotes that are inside closed quotes should be accepted
 * returns 1 if the input is valid, 0 otherwise
 * returns 0 if it's inside any quotes, 1 otherwise
 */

int check_quotes(char *line)
{
	int i;
	int singleq;
	int doubleq;

	i = 0;
	singleq = 0;
	doubleq = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == 39 && doubleq % 2 == 0)
			singleq += 1;
		else if (line[i] == 34 && singleq % 2 == 0)
			doubleq += 1;
		i++;
	}
	if (singleq % 2 == 0 && doubleq % 2 == 0)
		return (1);
	return (0);
}
