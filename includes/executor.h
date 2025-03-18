/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:58:02 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/18 07:57:53 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../includes/minishell.h"

/* execute_builtins.c */
int		execute_builtin(t_msh *msh, char **args, char ***export, int fd); // in ou out (?)

/* fork_and_execute1.c */
void	handle_error(const char *message);
void	redirect_input(t_exec *exec);
void	redirect_output(t_exec *exec);
void	fork_and_execute_command(char **args, t_exec *exec, char **env);

/* fork_and_execute2.c */
void	setup_pipe_and_execute(char **args, int *input_fd, char **env);
void	wait_for_children(int num_commands);
void	execute_multiple_pipes(char ***commands, int num_commands, char **env);

/* init_exec.c */
int		init_exec(t_msh *msh);

/* redirections1.c */
void	handle_input_redirection(char **args, int *in_fd, int i); // *in_fd é pointer e n pode ser substituido pelo exec->in_fd
void	handle_output_redirection(char **args, int *out_fd, int i); // same
void	handle_append_redirection(char **args, int *out_fd, int i); // same
void	handle_redirections(char **args, int *in_fd, int *out_fd); // same
void	execute_command(char **args, t_exec *exec, char **env);

/* redirections2.c */
void	child_process_logic(char **args, char **env);
void	execute_with_redirections(char **args, char **env);

#endif
