/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:58:48 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/16 17:22:09 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	execute_builtin(char **env, char **args) // questão de nem todas terem env (provavelmente dividir em 2 funcs uma para os que têm e outra não)
{
	if (args[0] == NULL)
		return (0);
	if (strcmp(args[0], "cd") == 0) // ✅
		cd_command(env, args);
	else if (strcmp(args[0], "export") == 0) // a ser visto
		export_command(args, env, fd);
	else if (strcmp(args[0], "unset") == 0) // a ser visto
		exec_unset(env, &export_command(args, env, fd), args, exit_status);
	else if (strcmp(args[0], "exit") == 0) // ✅
		exec_exit(args);
	else if (strcmp(args[0], "env") == 0) // a ser visto
		builtin_env(args);
	else if (strcmp(args[0], "pwd") == 0) // a ser visto
		my_pwd(fd);
	else if (strcmp(args[0], "echo") == 0) // ✅
		run_echo(args);
	else
		return (0);
	return (1);
}

