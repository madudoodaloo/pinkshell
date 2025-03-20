/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:20:57 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 16:17:46 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	run_doc(char *delimiter, t_exec *exec, int k)
{
	int	pid;

	if (pipe(exec[k].pipe_fd) < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		safe_close(exec[k].pipe_fd);
		return (-1);
	}
	if (pid == 0)
		read_into_heredoc(delimiter, exec, k);
	ft_waitpid(pid);
	if (msh()->exit_status == 130)
		return (-1);
	if (msh()->exit_status == 169)
	{
		exec[k].cmd_invalid = true;
		msh()->exit_status = 0;
	}
}

void	read_into_heredoc(char *delimiter, t_exec *exec, int k)
{
	char	*str;

	signal(SIGINT, SIG_DFL);
	safe_close(exec->pipe_fd[0]);
	while (1)
	{
		str = readline("> ");
		if (!str)
			control_d_handle(exec, k, str);
		if (ft_strcmp(str, delimiter) == 0)
			break ;
		write_to_pipe(str, exec);
	}
	safe_close(exec->pipe_fd[1]);
	exit(0);
}

void	control_d_handle(t_exec *exec, int k, char *str)
{
	if (!str)
		return ;
	safe_close(exec->pipe_fd[1]);
	exit(169);
}

void	write_to_pipe(char *str, t_exec *exec)
{
	char	*s1;

	s1 = ft_strjoin(str, "\n");
	write(exec->pipe_fd[1], &s1, ft_strlen(str));
	free(s1);
}
