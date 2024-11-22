/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 07:08:43 by msilva-c          #+#    #+#             */
/*   Updated: 2024/11/22 11:42:28 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int count_quotes(char *line, int i)
{
	int count;

	count = 0;
	while (line[i])
	{
		if (line[i] == 39 || line[i] == 34)
			count++;
		i++;
	}
	return (count % 2);
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
