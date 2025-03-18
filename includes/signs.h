/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:26:02 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/18 02:08:02 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNS_H
# define SIGNS_H

# include "../includes/minishell.h"

typedef struct s_data
{
	bool is_heredoc; // Flag to indicate heredoc mode
	void *strut;     // Placeholder for resources to free
	char **envp;     // Environment variables
}		t_data;

/*signals1.c*/
void	signal_handler(t_data *data, int signum);
void	handle_signals_and_cleanup(t_data *data);
void	setup_signals(void);
void	restore_parent_signals(void);
void	handle_child_exit_status(int status);

/*signals2.c*/
void	handle_ctrl_d(char *line);
void	handle_sigint(t_data *data, char *temp_filename);
void	handle_sigquit(t_data *data);

#endif
