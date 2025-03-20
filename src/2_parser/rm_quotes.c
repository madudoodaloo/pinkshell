/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 04:54:10 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/20 04:54:38 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



void	rm_quotes_pipex(t_exec	*exec)
{
	int		i;
	int index;

	i = -1;
	index = 0;
	while (index < exec[0].nbr_cmds)
	{
		while (exec[index].redir_in && exec[index].redir_in[++i])
			exec[index].redir_in[i] = rm_quote(exec[index].redir_in, i);
		i = -1;
		while (exec[index].redir_out && exec[index].redir_out[++i])
			exec[index].redir_out[i] = rm_quote(exec[index].redir_out, i);
		i = -1;
		while (exec[index].args && exec[index].args[++i])
			exec[index].args[i] = rm_quote(exec[index].args, i);
	}
}
