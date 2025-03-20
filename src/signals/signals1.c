/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:26:33 by marianamest       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/17 17:27:29 by marianamest      ###   ########.fr       */
=======
/*   Updated: 2025/03/19 23:55:46 by msilva-c         ###   ########.fr       */
>>>>>>> 1b3a26233614e8e1c79ebd318651765b6d918b75
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler(t_exec * exec, int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
<<<<<<< HEAD
		if (msdata()->is_heredoc) // se estiver dentro do modo heredoc vai sair
		{
			msdata()->is_heredoc = 0;
				// reset da flag para 0 para indicar que o heredoc ja nao esta ativo
=======
		if (data->is_heredoc)
		{
			data->is_heredoc = 0;
>>>>>>> 1b3a26233614e8e1c79ebd318651765b6d918b75
			g_signal = SIGINT;
			close(STDIN_FILENO);
			return ;
		}
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal = SIGINT;
	}
}

void	handle_signals_and_cleanup(t_exec * exec)
{
	if (g_signal == SIGINT)
	{
		g_signal = 0;
		if (data->is_heredoc)
		{
			free_all(data->strut);
<<<<<<< HEAD
				// se estiver no heredoc limpa a memoria que estava alocada
			exit(130);             // codigo do SIGINT
		}
		else
			write(1, "\n", 1);
				// se nao estiver em heredoc mete so na linha nova do prompt
=======
			exit(130);
		}
		else
			write(1, "\n", 1);
>>>>>>> 1b3a26233614e8e1c79ebd318651765b6d918b75
	}
	else if (g_signal == SIGQUIT)
	{
		g_signal = 0;
		write(STDERR_FILENO, "Quit (core dumped)\n", 20);
	}
}

void	setup_signals(void)
{
	struct sigaction	sa;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
	rl_clear_signals();
}

void	restore_parent_signals(void)
{
	struct sigaction sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
<<<<<<< HEAD
		// applica as configurações dos sinais ao SIGINT e SIGQUIT
=======
>>>>>>> 1b3a26233614e8e1c79ebd318651765b6d918b75
	sigaction(SIGQUIT, &sa, NULL);
}

void	handle_child_exit_status(int status)
{
	int	signal;

<<<<<<< HEAD
	if (WIFSIGNALED(status))// verifica se a child terminou por causa de um sinal
	{
		signal = WTERMSIG(status);// macro que sevolve true se tiver (status é exit status do child process)
		if (signal == SIGINT)
			write(1, "\n", 1);
		else if (signal == SIGQUIT)
			write(STDERR_FILENO, "Quit (core dumped)\n", 20);// mensagem standard
=======
	if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		if (signal == SIGINT)
			write(1, "\n", 1);
		else if (signal == SIGQUIT)
			write(STDERR_FILENO, "Quit (core dumped)\n", 20);
>>>>>>> 1b3a26233614e8e1c79ebd318651765b6d918b75
	}
}
