/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:04:15 by marianamest       #+#    #+#             */
/*   Updated: 2024/11/06 18:22:06 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_command(char **env, char **args) // if given none or 1 arg (ex.: cd or cd Documents are acceptable), otherwise uses change directory if the target defaults to NULL
{
	if (args[1] && args[2])
		return ;
	change_directory(env, args[1] ? args[1] : NULL);
}

char	*create_env_entry(const char *key, const char *value) // allocates and fills a string in the KEY = value format
{
	int		i;
	int		j;
	char	*entry;

	i = 0;
	j = 0;
	entry = malloc(strlen(key) + strlen(value) + 2);
	if (!entry)
		return (NULL);
	while (key[i])
	{
		entry[i] = key[i];
		i++;
	}
	entry[i++] = '=';
	while (value[j])
		entry[i++] = value[j++];
	entry[i] = '\0';
	return (entry);
}

int	find_env_key_index(char **env, const char *key) // searches for and returns a given key's index (if there's none it returns (-1))
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (key[j] && key[j] == env[i][j])
			j++;
		if (!key[j] && env[i][j] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	**expand_env(char **env, char *new_entry) // expands env to add 1 new var and sets it to NULL
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = malloc((i + 2) * sizeof(char *));
	if (!new_env)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_env[j] = env[j];
		j++;
	}
	new_env[i] = new_entry;
	new_env[i + 1] = NULL;
	return (new_env);
}

void	set_or_add_env_value(char ***env, const char *key, const char *value) // adds or updates an env variable (depending on if it already exists or not)
{
	int		index;
	char	*new_entry;

	index = find_env_key_index(*env, key);
	new_entry = create_env_entry(key, value);
	if (!new_entry)
		return ;
	if (index != -1)
	{
		free((*env)[index]);
		(*env)[index] = new_entry;
	}
	else
		*env = expand_env(*env, new_entry);
}
