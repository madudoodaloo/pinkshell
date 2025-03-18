/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:58:24 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/18 02:11:29 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	handle_redirections(char **args, int *in_fd, int *out_fd)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strcmp(args[i], "<") == 0)
			handle_input_redirection(args, in_fd, i);
		else if (ft_strcmp(args[i], ">") == 0)
			handle_output_redirection(args, out_fd, i);
		else if (ft_strcmp(args[i], ">>") == 0)
			handle_append_redirection(args, out_fd, i);
		i++;
	}
}

void	execute_command(char **args, int input_fd, int output_fd, char **env)
{
	if (input_fd != -1)
		redirect_input(input_fd);
	if (output_fd != -1)
		redirect_output(output_fd);
	if (execve(args[0], args, env) == -1)
		handle_error("execve");
}
