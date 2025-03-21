/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:04 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/21 02:42:41 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int if_var_exists(char *name)
{
	t_env *env;

	env = msh()->env;
	while(env)
	{
		if(!ft_strcmp(name, env->var_name))
			return(1);
		env = env->next;
	}
	return(0);
}

void remove_var(char *name)
{
	t_env *env;

	env = msh()->env;
	while(env)
	{
		if(env->next && !ft_strcmp(env->next->var_name, name))
		{
			if(env->next->next)
				env->next = env->next->next;
			free(env->next->var_name);
			free(env->next->var_value);
			free(env->next);
		}
	}
}

void	exec_unset(char **args)
{
	int	i;

	if (!args || !msh()->env)
		return ;
	i = 1;
	while (args[i])
	{
		if(if_var_exists(args[i]))
			remove_var(args[i]);
		i++;
	}
	msh()->exit_status = 0;
}
