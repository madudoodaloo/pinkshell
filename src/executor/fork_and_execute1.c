/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_execute1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:05:44 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/17 21:45:20 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_error(const char *message)
{
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	redirect_input(int input_fd)
{
	if (input_fd != STDIN_FILENO)
	{
		if (dup2(input_fd, STDIN_FILENO) == -1)
			handle_error("dup2");
		close(input_fd);
	}
}

void	redirect_output(int output_fd)
{
	if (output_fd != STDOUT_FILENO)
	{
		if (dup2(output_fd, STDOUT_FILENO) == -1)
			handle_error("dup2");
		close(output_fd);
	}
}

void	execute_command(char **args, int input_fd, int output_fd, char **env)
{
	redirect_input(input_fd);
	redirect_output(output_fd);
	if (execve(args[0], args, env) == -1)
		handle_error("execve");
}

void	fork_and_execute_command(char **args, int input_fd, int output_fd,
		char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execute_command(args, input_fd, output_fd, env);
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
		handle_error("fork");
}

// int main() {
//     // Example command line: ls | grep .c | wc -l
//     char *command1[] = {"/bin/ls", NULL};
//     char *command2[] = {"/usr/bin/grep", ".c", NULL};
//     char *command3[] = {"/usr/bin/wc", "-l", NULL};

//     // Array of commands
//     char ***commands = (char ***)malloc(3 * sizeof(char **));
//     commands[0] = command1;
//     commands[1] = command2;
//     commands[2] = command3;

//     // Execute the pipeline
//     execute_multiple_pipes(commands, 3);

//     // Free memory
//     free(commands);

//     return (0);
// }
