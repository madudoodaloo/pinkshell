/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:58:48 by marianamest       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/20 18:02:03 by marianamest      ###   ########.fr       */
=======
/*   Updated: 2025/03/20 17:36:47 by msilva-c         ###   ########.fr       */
>>>>>>> 7eb6f63287817aab39cbe773a6df862b7dad1f2e
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//nana o que
int	execute_builtin(t_msh *msh, char **args, char **wtf, int fd)
<<<<<<< HEAD
{	
	t_env *env;
	
	env = msh->env;
	if (fd == -1)
		fd = STDOUT_FILENO;
	if (ft_strcmp(args[0], "cd") == 0)
		cd(get_matrix_env(env), fd);
=======
{
	(void) msh;
	(void) args;
	(void) wtf;
	if (fd == -1)
		fd = STDOUT_FILENO;
/* 	if (ft_strcmp(args[0], "cd") == 0)
		cd(get_matrix_env(msh->env), args);
>>>>>>> 7eb6f63287817aab39cbe773a6df862b7dad1f2e
	else if (ft_strcmp(args[0], "export") == 0)
		export_command(args, env, fd);
	else if (ft_strcmp(args[0], "unset") == 0)
		exec_unset(get_matrix_env(env), wtf, args, &msh->exit_status);
	else if (ft_strcmp(args[0], "exit") == 0)
		exec_exit(args);
	else if (ft_strcmp(args[0], "env") == 0)
		general_manage_env(get_matrix_env(env),/*fun que da a ação*/,get_matrix_env(env));
	else if (ft_strcmp(args[0], "pwd") == 0)
		pwd(fd);
	else if (ft_strcmp(args[0], "echo") == 0)
		run_echo(args);
 */	else
		return (0);
	return (1);
}

//void	execute_builtin_in_fork(/*whatever it requires*/)// check if void is appropriate and add to .h file
//{
//	execute_builtin(/*args required*/);
//	exit(msh()->exit_status);
//}

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
