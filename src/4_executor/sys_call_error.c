/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_call_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:42:43 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/20 14:43:36 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	pipe_error(void)
{
	perror("pipe");
	msh()->exit_status = 1;
	return (-1);
}

void	close_fds(int *fds)
{
	if_close(fds[0]);
	close(fds[1]);
}

int	fork_error(void)
{
	perror("fork");
	msh()->exit_status = 1;
	return (-1);
}


