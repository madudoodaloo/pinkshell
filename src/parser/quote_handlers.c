/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 07:08:43 by msilva-c          #+#    #+#             */
/*   Updated: 2024/11/22 07:31:52 by msilva-c         ###   ########.fr       */
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

	printf("\n--- entered quote handler ---\n");
	wdlen = strchr_wdlen(&cmdline[i], cmdline[i]);
	if (wdlen)
	{
		//int test = i + wdlen;
		//int ii = i;
		//while (ii < test)
		//	printf("%c", cmdline[ii++]);
		//printf("$\n\n");
		add_node(lst_head, cmdline, i, i + wdlen);
		return (wdlen);
	}
	printf("skipped quote\n");
	return (1);
}
