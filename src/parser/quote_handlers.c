/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 07:08:43 by msilva-c          #+#    #+#             */
/*   Updated: 2024/12/05 15:55:04 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int count_quotes(char *line, int i)
{
	int singles;
	int doubles;

	singles = 0;
	doubles = 0;
	while (line[i])
	{
		if (line[i] == 39)
			singles++;
		else if (line[i] == 34)
			doubles++;
		i++;
	}
	singles %= 2;
	doubles %= 2;
	if (!singles && !doubles)
		return (0);
	return (1);
}

int	quote_handler(char *cmdline, int i, t_token **lst_head)
{
	int		wdlen;

	wdlen = strchr_wdlen(&cmdline[i], cmdline[i]);
	if (wdlen)
	{
		add_node(lst_head, cmdline, i, i + wdlen);
		return (wdlen);
	}
	return (1);
}
