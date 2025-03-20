/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:40:50 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 13:19:35 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
 
void	update_pwd(void)
{
	t_env	*env;
	char	*old_pwd;

	env = msh()->env;
	while (env)
	{
		if (ft_strcmp(env->var_name, "PWD") == 0)
		{
			old_pwd = env->var_value;
			env->var_value = getcwd(NULL, 0);
			free(old_pwd);
			return ;
		}
		env = env->next;
	}
}

void	cd(char **args, int fd)
{
	char	env_var[4128];
	char	wd[4096];

	if (!args[1] || (!ft_strncmp(args[1], "~/", ft_strlen("~/"))
			&& ft_strlen(args[1]) == ft_strlen("~/")) || (args[1][0] == '~'
			&& !args[1][1]))
		args[1] = get_var_value(msh()->env, "HOME");
	if (chdir(args[1]))
	{
		write(2, "minishell: cd: ", 15);
		perror(args[1]);
		msh()->exit_status = 1;
		return ;
	}
	if (getcwd(wd, sizeof(wd)) == NULL)
	{
		perror("minishell: pwd: ");
		msh()->exit_status = 1;
		return ;
	}
	ft_strlcpy(env_var, "PWD=", sizeof(env_var));
	ft_strlcat(env_var, wd, sizeof(env_var));
	update_pwd();
	export((char *[]){"export", env_var, NULL}, fd);
	msh()->exit_status = 0;
}
