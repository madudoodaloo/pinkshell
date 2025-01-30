/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:20:31 by marianamest       #+#    #+#             */
/*   Updated: 2024/11/22 04:52:32 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*create_env_entry(const char *key, const char *value)// creates an environment entry in "KEY=value" format
{
	int key_len;
	int value_len;
	char *entry;

	key_len = ft_strlen(key);
	value_len = ft_strlen(value);
	entry = (char *)malloc(key_len + value_len + 2);
	if (!entry)
		return (NULL);
	my_strcpy(entry, key);
	my_strcat(entry, "=");
	my_strcat(entry, value);
	return (entry);
}

char	**allocate_and_init_env_array(char **envp) // allocates memory for an array of strings to store environment variables.
{
	int	i;

	i = 0;
	while (envp[i]) // Count number of environment variables
		i++;
	char **env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	return (env);
}

int	process_env_variable(char *env_var, char **env, int i) // processes a single env var (in the "KEY=value" format) and stores it in the env array.
{
	char	*equal_sign;
	int		key_len;
	char	*key;
	char	*value;

	equal_sign = env_var;
	while (*equal_sign && *equal_sign != '=')
		equal_sign++;
	key_len = equal_sign - env_var;// Calculate key length and allocate memory for key
	key = (char *)malloc(key_len + 1);
	if (!key)
		return (0);
	my_strcpy(key, env_var);
	value = equal_sign + 1;
	env[i] = create_env_entry(key, value);// Create the full "KEY=value" entry and store it in the array
	free(key);
	if (!env[i])
		return (0);
	return (1);
}

char	**init_env_array(char **envp) // initializes the env array by allocating memory and processing each env var from the envp array.
{
	int		i;
	char	**env;

	i = 0;
	env = allocate_and_init_env_array(envp);
	if (!env)
		return (NULL);
	while (envp[i])// Process each environment variable
	{
		if (!process_env_variable(envp[i], env, i))// If processing the variable fails, frees allocated memory and returns NULL
		{
			while (i > 0)
				free(env[--i]);
			free(env);
			return (NULL);
		}
		i++;
	}
	env[i] = NULL;
	return (env);
}
