/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:26:02 by marianamest       #+#    #+#             */
/*   Updated: 2025/01/30 17:28:04 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"
//# include <stdbool.h>

typedef struct s_data
{
	bool is_heredoc; // Flag to indicate heredoc mode
	void *strut;     // Placeholder for resources to free
	char **envp;     // Environment variables
}		t_data;

t_data	*msdata(void)
{
	static t_data	data;

	return (&data);
}


void	signal_handler(int signum);
void	handle_signals_and_cleanup(t_data *data);
void	setup_signals(int is_main_shell, int is_heredoc);
void	restore_parent_signals(void);
void	handle_child_exit_status(int status);


#endif