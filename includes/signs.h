/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:26:02 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/16 15:29:36 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNS_H
# define SIGNS_H

# include "minishell.h"

// extern int g_signal; (?)
// volatile sig_atomic_t	g_signal = 0; (?)
typedef struct s_data
{
	bool is_heredoc; // Flag to indicate heredoc mode
	void *strut;     // Placeholder for resources to free
	char **envp;     // Environment variables
}		t_data;

t_data  *msdata(void);

/*signals 1*/
void	signal_handler(int signum);
void	handle_signals_and_cleanup(t_data *data);
void	setup_signals(void);
void	restore_parent_signals(void);
void	handle_child_exit_status(int status);

/*signals 2*/
void	handle_ctrl_d(char *line);
void	handle_sigint(char *temp_filename);
void	handle_sigquit(void);
#endif
