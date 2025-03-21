/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:36:18 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/20 19:57:37 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int	check_redirs(t_exec *ex)
{
	if (prep_in_redir(ex) < 0)
		return (-1);
	if (prep_out_redir(ex) < 0)
		return (-1);
	return (1);
}

void do_input_redir(t_exec *ex)
{
	if (ex->index > 0)
	{
		if (!ex->redir_in)
			dup2(ex->prev_pipe_fd, 0);
		safe_close(ex->prev_pipe_fd);
	}
	if (ex->redir_in && ex->redir_in[0])
	{
		if (ex->is_heredoc)
		{
			dup2(ex->pipe_doc[0], 0);
			safe_close(ex->pipe_doc[0]);
		}
		else
		{
			dup2(ex->in_fd, 0);
			safe_close(ex->in_fd);
		}
	}
}

void do_output_redir(t_exec *ex)
{
	if (ex->index < ex->nbr_cmds - 1 && !ex->redir_out)
		dup2(ex->pipe_fd[1], 0);
	if (ex->redir_out)
		dup2(ex->out_fd, 0);
	safe_close(ex->prev_pipe_fd);
}
