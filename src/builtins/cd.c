/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:40:50 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 21:01:52 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd(char **args, int fd)
{
	(void)fd;
	char	env_var[4128];
	char	cwd[4096];

	if (!args || chdir(args[1]))
	{
		write(2, "minishell: cd: ", 15);
		perror(args[1]);
		msh()->exit_status = 1;
		return ;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("get cwd error.");
		msh()->exit_status = 1;
		return ;
	}
	ft_strlcpy(env_var, "PWD=", sizeof(env_var));
	ft_strlcat(env_var, cwd, sizeof(env_var));
	update_pwd();
	//export((char *[]){"export", env_var, NULL}, fd);
	msh()->exit_status = 0;
}
