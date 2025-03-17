/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:58:48 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/16 23:48:56 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/executor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int execute_builtin(char **args, char ***env, char ***export, int *exit_status, int fd) // max 4 por func
{
	int local_exit_status;
	
	local_exit_status = 0;
	if (exit_status == NULL)
		exit_status = &local_exit_status;
	if (fd == -1) 
		fd = STDOUT_FILENO;
	if (ft_strcmp(args[0], "cd") == 0) // ✅
		builtin_cd(args);
	else if (ft_strcmp(args[0], "export") == 0) // ✅
		export_command(args, env, fd);	
	else if (ft_strcmp(args[0], "unset") == 0) // ✅
		exec_unset(*env, *export, args, exit_status); // não esta a receber bem o export(refere-se ao resultado da função export e nao a aum double array)
	else if (ft_strcmp(args[0], "exit") == 0) // ✅
		exec_exit(args);
	// else if (ft_strcmp(args[0], "env") == 0) // ‼️‼️
	// 	builtin_env(args);
	else if (ft_strcmp(args[0], "pwd") == 0) // ✅
		my_pwd(fd);
	else if (ft_strcmp(args[0], "echo") == 0) // ✅
		run_echo(args);
	else
		return (0);
	return (1);
}
