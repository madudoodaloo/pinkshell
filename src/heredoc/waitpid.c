/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:22:09 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 14:35:03 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	write_to_pipe(char *str, t_exec *exec)
{
	char	*s1;

	s1 = ft_strjoin(str, "\n");
	write(exec->pipe_fd[1], &s1, ft_strlen(str));
	free(s1);
}