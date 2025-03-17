/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:58:02 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/17 21:26:19 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

/* redirections1 */
void	handle_input_redirection(char **args, int *in_fd, int i);
void	handle_output_redirection(char **args, int *out_fd, int i);
void	handle_append_redirection(char **args, int *out_fd, int i);
void	handle_redirections(char **args, int *in_fd, int *out_fd);
void	execute_command(char **args, int input_fd, int output_fd, char **env);

/* redirections2 */
void	child_process_logic(char **args, char **env);
void	execute_with_redirections(char **args, char **env);

/* builtins */
int		execute_builtin(t_msh *msh, char **args, char ***export, int fd);

/* fork_and_execute1 */
void	handle_error(const char *message);
void	redirect_input(int input_fd);
void	redirect_output(int output_fd);
void	execute_command(char **args, int input_fd, int output_fd, char **env);
void	fork_and_execute_command(char **args, int input_fd, int output_fd,
			char **env);

/* fork_and_execute2 */
void	setup_pipe_and_execute(char **args, int *input_fd, char **env);
void	wait_for_children(int num_commands);
void	execute_multiple_pipes(char ***commands, int num_commands, char **env);

/* exec_parser */

#endif