/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:26:33 by marianamest       #+#    #+#             */
/*   Updated: 2025/01/30 17:48:33 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

volatile sig_atomic_t	g_signal = 0;

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\nCaught SIGINT (Ctrl+C)\n", 24);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal = SIGINT;
		if (msdata()->is_heredoc)
			close(STDIN_FILENO);
	}
	else if (signum == SIGQUIT)
	{
		write(1, "Caught SIGQUIT (Ctrl+\\)\n", 25);
		g_signal = SIGQUIT;
		if (!msdata()->is_heredoc)
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
}

void	handle_signals_and_cleanup(t_data *data)
{
	if (g_signal == SIGINT)
	{
		g_signal = 0;
		if (data->is_heredoc)
		{
			free_all(data->strut);
			exit(130);
		}
		else
			write(1, "\n", 1);
	}
	else if (g_signal == SIGQUIT)
	{
		g_signal = 0;
		write(STDERR_FILENO, "Quit (core dumped)\n", 20);
	}
}

void	setup_signals(int is_main_shell, int is_heredoc)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	if (is_main_shell)
		sa.sa_handler = SIG_IGN;
	else
		sa.sa_handler = signal_handler;
	sigaction(SIGQUIT, &sa, NULL);
	if (!is_main_shell && !is_heredoc)
	{
		sa.sa_handler = SIG_DFL;
		sigaction(SIGINT, &sa, NULL);
		sigaction(SIGQUIT, &sa, NULL);
	}
}

void	restore_parent_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	handle_child_exit_status(int status)
{
	int	signal;

	if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		if (signal == SIGINT)
			write(1, "\n", 1);
		else if (signal == SIGQUIT)
			write(STDERR_FILENO, "Quit (core dumped)\n", 20);
	}
}
