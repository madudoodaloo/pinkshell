/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_execute2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:25:57 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/16 23:24:33 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/executor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void	setup_pipe_and_execute(char **args, int *input_fd, char **env)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		handle_error("pipe");
	fork_and_execute_command(args, *input_fd, pipefd[1], env);
	close(pipefd[1]);
	*input_fd = pipefd[0];
}

void	wait_for_children(int num_commands)
{
	int		i;
	int		status;
	pid_t	pid;

	i = 0;
	while (i < num_commands)
	{
		pid = waitpid(-1, &status, 0);
		if (pid > 0)
			handle_child_exit_status(status);
		else
			handle_error("waitpid");
		i++;
	}
}

void	execute_multiple_pipes(char ***commands, int num_commands, char **env)
{
	int	input_fd;
	int	i;

	input_fd = STDIN_FILENO;
	i = 0;
	while (i < num_commands - 1)
	{
		setup_pipe_and_execute(commands[i], &input_fd, env);
		i++;
	}
	fork_and_execute_command(commands[num_commands - 1], input_fd,
		STDOUT_FILENO, env);
	close(input_fd);
	wait_for_children(num_commands);
}
