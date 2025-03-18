/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:40:50 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/18 02:11:29 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*find_env_value(char **env, const char *var)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (var[j] && var[j] == env[i][j])
			j++;
		if (!var[j] && env[i][j] == '=')
			return (&env[i][j + 1]);
		i++;
	}
	return (NULL);
}

static int	change_dir(const char *path)
{
	if (chdir(path) == -1)
	{
		perror("cd: chdir() error");
		return (-1);
	}
	return (0);
}

void	change_directory(char **env, const char *path)
{
	char	old_pwd[MAXPATH];
	char	new_pwd[MAXPATH];

	if (getcwd(old_pwd, sizeof(old_pwd)) == NULL)
	{
		perror("cd: getcwd() error");
		return ;
	}
	if (!path)
	{
		path = find_env_value(env, "HOME");
		if (!path)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return ;
		}
	}
	if (change_dir(path) == -1)
		return ;
	if (getcwd(new_pwd, sizeof(new_pwd)) == NULL)
	{
		perror("cd: getcwd() error");
		return ;
	}
	printf("Changed directory from %s to %s\n", old_pwd, new_pwd);
}

void	cd_command(char **env, char **args)
{
	const char	*path;

	if (args[1] && args[2])
	{
		write(STDERR_FILENO, "cd: too many arguments\n", 23);
		return ;
	}
	if (args[1] != NULL)
		path = args[1];
	else
		path = NULL;
	change_directory(env, path);
}
