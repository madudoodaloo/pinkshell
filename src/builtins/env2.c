/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:31:05 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/16 21:40:03 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	find_env_key_index(char **env, const char *key) // searches for the index of an env var by its key in the env array.
{
	int	i;
	int	key_len;
	int	j;

	i = 0;
	key_len = ft_strlen(key);
	while (env[i])
	{
		j = 0;
		while (key[j] && key[j] == env[i][j])
			j++;
		if (j == key_len && env[i][j] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	**update_env_var(char *arg, char **env, int idx) // updates the value of an existing env var, in the index idx in the env array, with arg as value
{
	char	*equal_sign;
	char	*key;
	char	*value;
	int key_len;

	equal_sign = arg;// Find the '=' character in the arg string
	while (*equal_sign && *equal_sign != '=') // if no ""="" was found
		equal_sign++;
	if (*equal_sign != '=')
		return (NULL);
	key_len = equal_sign - arg; // Length of the key
	key = (char *)malloc(key_len + 1);
	if (!key)
		return (NULL);
	my_strcpy(key, arg);
	value = equal_sign + 1;// The value is everything after the '=' character
	free(env[idx]);
	env[idx] = create_env_entry(key, value);// Create the new environment variable with the key and value
	free(key);
	if (!env[idx])
		return (NULL);
	return (env);
}

char	**expand_env(char **env, char *new_entry)// expands env to add 1 new var and sets it to NULL
{
	int i;
	int j;
	char **new_env;

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

void	set_or_add_env_value(char ***env, const char *key, const char *value)// adds or updates an env variable (depending on if it already exists or not)
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
