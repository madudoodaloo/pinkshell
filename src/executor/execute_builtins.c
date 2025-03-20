/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:58:48 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 17:30:44 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//nana o que
int	execute_builtin(t_msh *msh, char **args, char **wtf, int fd)
{
	if (fd == -1)
		fd = STDOUT_FILENO;
	if (ft_strcmp(args[0], "cd") == 0)
		cd(get_matrix_env(msh->env), args);
	else if (ft_strcmp(args[0], "export") == 0)
		export_command(args, get_matrix_env(msh->env), fd);
	else if (ft_strcmp(args[0], "unset") == 0)
		exec_unset(get_matrix_env(msh->env), wtf, args, msh->exit_status);
	else if (ft_strcmp(args[0], "exit") == 0)
		exec_exit(args);
	else if (ft_strcmp(args[0], "env") == 0)
		builtin_env(get_matrix_env(msh->env), fd);
	else if (ft_strcmp(args[0], "pwd") == 0)
		pwd(fd);
	else if (ft_strcmp(args[0], "echo") == 0)
		run_echo(args);
	else
		return (0);
	return (1);
}

void	execute_builtin_in_fork(/*whatever it requires*/)// check if void is appropriate and add to .h file
{
	execute_builtin(/*args required*/);
	exit(msh()->exit_status);
}

int	is_builtin(char *command) // bota struct maybe
{
	if (ft_strcmp(command, "cd") == 0 || ft_strcmp(command, "export") == 0
		|| ft_strcmp(command, "unset") == 0 || ft_strcmp(command, "exit") == 0
		|| ft_strcmp(command, "env") == 0 || ft_strcmp(command, "pwd") == 0
		|| ft_strcmp(command, "echo") == 0)
	{
		return (1);
	}
	return (0);
}
