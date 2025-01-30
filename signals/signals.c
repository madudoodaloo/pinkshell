/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:20:19 by marianamest       #+#    #+#             */
/*   Updated: 2025/01/30 16:11:43 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t g_signal = 0;

void signal_handler(int signum)
{
    nana
    if (signum == SIGINT)
    {
        write(1, "\n", 1);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
        g_signal = SIGINT;

        if (msdata()->is_heredoc)
            close(STDIN_FILENO);
    }
    else if (signum == SIGQUIT)
        g_signal = SIGQUIT;
}

void handle_signals_and_cleanup(t_data *data)
{
    if (g_signal == SIGINT)
    {
        g_signal = 0;
        if (data->is_heredoc)
        {
            free_all(data->strut);
            free_array(data->envp);
            exit(130);
        }
        else
            printf("\n");
    }
    else if (g_signal == SIGQUIT)
    {
        g_signal = 0;
        ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
    }
}

void setup_signals(int is_main_shell, int is_heredoc)
{
    if (is_main_shell || is_heredoc)
    {
        signal(SIGINT, signal_handler);
        signal(SIGQUIT, is_main_shell ? SIG_IGN : signal_handler);
    }
    else
    {
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
    }
}
