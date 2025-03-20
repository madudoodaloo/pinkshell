/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:22:09 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 13:12:22 by marianamest      ###   ########.fr       */
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
