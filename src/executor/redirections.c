/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:58:24 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/16 21:14:45 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/executor.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	handle_input_redirection(char **args, int *in_fd, int i)
{
	*in_fd = open(args[i + 1], O_RDONLY);
	if (*in_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(*in_fd, STDIN_FILENO);
	close(*in_fd);
	args[i] = NULL;
}

void	handle_output_redirection(char **args, int *out_fd, int i)
{
	*out_fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*out_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(*out_fd, STDOUT_FILENO);
	close(*out_fd);
	args[i] = NULL;
}

void	handle_append_redirection(char **args, int *out_fd, int i)
{
	*out_fd = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*out_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(*out_fd, STDOUT_FILENO);
	close(*out_fd);
	args[i] = NULL;
}

void	execute_with_redirections(char **args)
{
	int	in_fd;
	int	out_fd;
	int	i;

	in_fd = -1;
	out_fd = -1;
	i = 0;
	while (args[i] != NULL)
	{
		if (strcmp(args[i], "<") == 0)
			handle_input_redirection(args, &in_fd, i);
		else if (strcmp(args[i], ">") == 0)
			handle_output_redirection(args, &out_fd, i);
		else if (strcmp(args[i], ">>") == 0)
			handle_append_redirection(args, &out_fd, i);
		i++;
	}
	if (execve(args[0], args, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

// int	main(void)
// {
// 	// Example command with redirections
// 	char *args[] = {"/bin/ls", ">", "output.txt", NULL};

// 	// Fork a child process to execute the command
// 	pid_t pid = fork();
// 	if (pid == 0)
// 	{
// 		// Child process: execute the command with redirections
// 		execute_with_redirections(args);
// 	}
// 	else if (pid > 0)
// 	{
// 		// Parent process: wait for the child to finish
// 		wait(NULL);
// 	}
// 	else
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}

// 	return (0);
// }