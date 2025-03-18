/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:58:48 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/18 02:11:29 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	execute_builtin(t_msh *msh, char **args, char ***export, int fd)
{
	if (msh->exit == NULL)
		msh->exit = 0;
	if (fd == -1)
		fd = STDOUT_FILENO;
	if (ft_strcmp(args[0], "cd") == 0)
		builtin_cd(args);
	else if (ft_strcmp(args[0], "export") == 0)
		export_command(args, msh->env, fd);
	else if (ft_strcmp(args[0], "unset") == 0)
		exec_unset(msh->env, *export, args, msh->exit);
	else if (ft_strcmp(args[0], "exit") == 0)
		exec_exit(args);
	else if (ft_strcmp(args[0], "env") == 0)
		builtin_env(msh->env, fd);
	else if (ft_strcmp(args[0], "pwd") == 0)
		my_pwd(fd);
	else if (ft_strcmp(args[0], "echo") == 0)
		run_echo(args);
	else
		return (0);
	return (1);
}
