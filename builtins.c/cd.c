/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:40:50 by marianamest       #+#    #+#             */
/*   Updated: 2025/01/11 19:12:35 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_env_value(char **env, const char *var) // searches through env to find the key we want and returns pointer to the value portion
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

int	get_current_directory(char *buffer, int size) // retrieves the current directory and stores it in buffer
{
	int	success;

	success = 0;
	while (!success)
		success = getcwd(buffer, size) != NULL;
	return (success);
}
void	set_env_value(char **env, const char *key, const char *value) // sets the environment variable key to the value
{
	int		i;
	char	*new_var;
	size_t	key_len;

	key_len = strlen(key);
	new_var = malloc(key_len + strlen(value) + 2);
	if (!new_var)
		return ;
	sprintf(new_var, "%s=%s", key, value);
	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], key, key_len) == 0 && env[i][key_len] == '=')
		{
			free(env[i]);
			env[i] = new_var;
			return ;
		}
		i++;
	}
	env[i] = new_var;
	env[i + 1] = NULL;
	env[i + 2] = NULL; // Ensure the env array is properly terminated
}
void	update_pwd_vars(char **env, const char *old_pwd, const char *new_pwd) // updates the current (PWD) and previous (OLDPWD) values
{
	set_env_value(env, "OLDPWD", old_pwd);
	set_env_value(env, "PWD", new_pwd);
}

void	change_directory(char **env, const char *path) // changes the current directory to either *path or HOME (in case of failure as a fallback option)
{
	char	old_pwd[PATH_MAX];
	char	new_pwd[PATH_MAX];

	if (!get_current_directory(old_pwd, sizeof(old_pwd)))
		return ;
	if (!path)
		path = find_env_value(env, "HOME");
	if (chdir(path) == 0 && get_current_directory(new_pwd, sizeof(new_pwd)))
		update_pwd_vars(env, old_pwd, new_pwd);
}

void	cd_command(char **env, char **args) // if given none or 1 arg (ex.: cd or cd Documents are acceptable), otherwise uses change directory if the target defaults to NULL
{
	if (args[1] && args[2])
		return ;
	change_directory(env, args[1] ? args[1] : NULL);
}
