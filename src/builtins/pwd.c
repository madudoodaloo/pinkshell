/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:32:36 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 21:08:28 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pwd(int fd)
{
    char	cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL && *cwd)
    {
        ft_putstr_fd(cwd, fd);
        write(fd, "\n", 1);
        msh()->exit_status = 0;
    }
    else
    {
        perror("minishell: pwd");
        msh()->exit_status = 1;
    }
}

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
