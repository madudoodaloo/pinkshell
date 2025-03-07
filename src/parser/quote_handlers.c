/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 07:08:43 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/07 14:47:22 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int count_quotes(char *line, int i)
{
	int flag = 1;
	char temp = 0;
	int max = ft_strlen(line);

	while (max > i)
	{
		if (line[i] == 34 || line[i] == 39)
		{
			temp = line[i];
			i++;
			while (max > i && flag)
			{
				if (line[i] == temp)
					flag = 0;
				else
					i++;
			}
			if (max == i)
				return (1);
		}
		i++;
	}
	return (0);
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
