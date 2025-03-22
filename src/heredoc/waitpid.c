/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:22:09 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/22 13:35:00 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_pipe(int *fd)
{
	safe_close(fd[0]);
	safe_close(fd[1]);
}

void	safe_close(int fd)
{
	if (fd > 2)
		close(fd);
}
/*
void	ft_waitpid(int pid)
{
	int	status;

	while (waitpid(pid, &status, 0) == -1) // se waitpid deu errro
	{
		if (errno == EINTR) // se foi system call error
			continue ;
		perror("waitpid");
		msh()->exit_status = 1;
		return ;
	}
	if (WIFEXITED(status))
		msh()->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		msh()->exit_status = 128 + WTERMSIG(status);
	else
		msh()->exit_status = 1;
}
 */
void	write_to_pipe(char *str, t_exec *exec)
{
	char	*s1;

	s1 = ft_strjoin(str, "\n");
	write(exec->pipe_fd[1], &s1, ft_strlen(str));
	free(s1);
}
