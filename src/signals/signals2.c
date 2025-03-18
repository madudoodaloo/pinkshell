/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:45:23 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/17 23:16:46 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_sigint(t_data *data, char *temp_filename)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_signal = SIGINT;
	if (data->is_heredoc && temp_filename)
	{
		unlink(temp_filename);
		free(temp_filename);
		temp_filename = NULL;
	}
	if (data->is_heredoc)
		close(STDIN_FILENO);
	exit(130);
}

void	handle_sigquit(t_data *data)
{
	write(1, "Caught SIGQUIT (Ctrl+\\)\n", 25);
	g_signal = SIGQUIT;
	if (!data->is_heredoc)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handle_ctrl_d(char *line)
{
	if (line == NULL)
	{
		write(1, "exit\n", 5);
		free(line);
		exit(0);
	}
}
