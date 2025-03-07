/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 07:08:43 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/06 12:25:56 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int count_quotes(char *line, int i)
{
	int singles;
	int doubles;

	singles = 0;
	doubles = 0;
	int flag = 1;
	char temp = 0;
	while (ft_strlen(line) - 1 <= i)
	{
		if (line[i] == 39 || line[i] == 34)
		{
			temp = line[i];
			i++;
			while (line[i] && flag)
			{
				printf("line[i] is %c and i=%d\n", line[i], i);
				if (!line[i])
					return (1);
				else if (line[i] == temp)
					flag = 0;
				else
					i++;
			}
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
