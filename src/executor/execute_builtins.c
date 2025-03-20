/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:58:48 by marianamest       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/17 17:42:02 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	execute_builtin(char **args, char ***env, char ***export, int *exit_status, int fd) // max 4 por func
{
	int local_exit_status;

	local_exit_status = 0;
	if (exit_status == NULL)
		exit_status = &local_exit_status;
	if (fd == -1)
		fd = STDOUT_FILENO;
	if (ft_strcmp(args[0], "cd") == 0)
		builtin_cd(args);
	else if (ft_strcmp(args[0], "export") == 0)
		export_command(args, env, fd);
	// else if (ft_strcmp(args[0], "unset") == 0)
	// 	exec_unset(*env, export_command(args, env, fd), args, exit_status); // não esta a receber bem o export(refere-se ao resultado da função export e nao a um double array)
	else if (ft_strcmp(args[0], "exit") == 0)
		exec_exit(args);
	else if (ft_strcmp(args[0], "env") == 0) // <<<<<<‼️ qual fução chamar
		builtin_env(args);
=======
/*   Updated: 2025/03/19 23:51:54 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	execute_builtin(t_msh *msh, char **args, char ***export, int fd)
{
	if (fd == -1)
		fd = STDOUT_FILENO;
	if (ft_strcmp(args[0], "cd") == 0)
		cd_command(get_matrix_env(msh->env), args);
	else if (ft_strcmp(args[0], "export") == 0)
		export_command(args, get_matrix_env(msh->env), fd);
	else if (ft_strcmp(args[0], "unset") == 0)
		exec_unset(get_matrix_env(msh->env), *export, args, msh->exit_status);
	else if (ft_strcmp(args[0], "exit") == 0)
		exec_exit(args);
	else if (ft_strcmp(args[0], "env") == 0)
		builtin_env(get_matrix_env(msh->env), fd);
>>>>>>> 1b3a26233614e8e1c79ebd318651765b6d918b75
	else if (ft_strcmp(args[0], "pwd") == 0)
		my_pwd(fd);
	else if (ft_strcmp(args[0], "echo") == 0)
		run_echo(args);
	else
		return (0);
	return (1);
}
