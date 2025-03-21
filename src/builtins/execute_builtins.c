/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:58:48 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/21 04:02:25 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_env(t_env *env, int fd)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (current->var_name && current->var_value)
		{
			write(fd, current->var_name, ft_strlen(current->var_name));
			write(fd, "=", 1);
			write(fd, current->var_value, ft_strlen(current->var_value));
			write(fd, "\n", 1);
		}
		current = current->next;
	}
}

int	execute_builtin(t_exec *exec)
{
	if (ft_strcmp(exec->args[0], "cd") == 0)
		cd(exec->args, exec->out_fd);
	else if (ft_strcmp(exec->args[0], "export") == 0)
		export_command(exec->args, msh()->env, exec->out_fd);
	else if (ft_strcmp(exec->args[0], "unset") == 0)
		exec_unset(exec->args);
	else if (ft_strcmp(exec->args[0], "exit") == 0)
		exec_exit(exec->args);
	else if (ft_strcmp(exec->args[0], "env") == 0)
		print_env(msh()->env, exec->out_fd);
	else if (ft_strcmp(exec->args[0], "pwd") == 0)
		pwd(exec->out_fd);
	else if (ft_strcmp(exec->args[0], "echo") == 0)
		run_echo(exec->args, exec->out_fd);
	else
		return (0);
	return (1);
}

// void	execute_builtin_in_fork(/*whatever it requires*/)// check if void is appropriate and add to .h file
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

char	*get_var_value(char *name)
{
	t_env	*env;

	env = msh()->env;
	if (!env)
		return (NULL);
	while (env)
	{
		if (env->next)
		{
			if (ft_strcmp(name, env->next->var_name))
				return (ft_strdup(name));
			env = env->next;
		}
	}
	return (NULL);
}
