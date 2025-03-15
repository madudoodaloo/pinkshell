/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:45:23 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/15 19:44:04 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_sigint(char *temp_filename)
{
	write(1, "\n", 1); // verifica que o prompt começa uma newline 
	rl_on_new_line(); // informa que o cursor passou para a newline
	rl_replace_line("", 0); // da replace da current input line com uma empty string
	rl_redisplay(); // da update do display para as cenas de cima
	g_signal = SIGINT; // da update do g_signal para o SIGINT
	if (msdata()->is_heredoc && temp_filename)  // se estiver em heredoc e houver filename
	{
		unlink(temp_filename); // apaga o file temporario
		free(temp_filename); // liberta a memoria
		temp_filename = NULL; // fica a null
	}
	if (msdata()->is_heredoc) // se esiver em heredoc fecha o stdin fd
		close(STDIN_FILENO);
	exit(130); // codigo do SIGINT
}

void	handle_sigquit(void)
{
	write(1, "Caught SIGQUIT (Ctrl+\\)\n", 25);
	g_signal = SIGQUIT;
	if (!msdata()->is_heredoc)
	{
		rl_on_new_line(); // informa que o cursor passou para a newline
		rl_redisplay(); // da update do display para as cenas de cima
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
