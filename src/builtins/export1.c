/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:07:55 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/14 16:47:39 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int	is_valid_var_char(char c, int is_first_char)
{
	if (is_first_char)
		return (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
	else
		return (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'));
}

int parse_export(char *str)
{
    int i;

    i = 0;
    if (!is_valid_var_char(str[i], 1))
        return (0);
    while (str[i] != '\0' && str[i] != '=')
    {
        if (!is_valid_var_char(str[i], 0))
            return (0);
        i++;
    }
    return (1);
}

void	format_export_var(const char *var)
{
	const char	*equals = strchr(var, '=');
	int			name_len;

	if (!equals)
		printf("declare -x %s\n", var);
	else
	{
		name_len = equals - var;
		printf("declare -x %.*s=\"%s\"\n", name_len, var, equals + 1);
	}
}

int	find_var_index(char **env, const char *var, int name_len)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, name_len) == 0 && (env[i][name_len] == '='
				|| env[i][name_len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

void	add_new_var(char ***env, const char *var)
{
	int		env_size;
	char	**new_env;
	int		i;

	env_size = 0;
	while ((*env)[env_size])
		env_size++;
	new_env = malloc((env_size + 2) * sizeof(char *));
	if (!new_env)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < env_size)
	{
		new_env[i] = (*env)[i];
		i++;
	}
	new_env[env_size] = ft_strdup(var);
	new_env[env_size + 1] = NULL;
	free(*env);
	*env = new_env;
}

// int main(void)
// {
//     // Initialize environment variables
//     char **env = malloc(4 * sizeof(char *));
//     env[0] = strdup("PATH=/usr/bin");
//     env[1] = strdup("HOME=/home/user");
//     env[2] = strdup("USER=testuser");
//     env[3] = NULL;

//     // Test 1: Print sorted environment variables
//     printf("Initial Environment:\n");
//     export_command((char *[]){ "export", NULL }, &env, 1);

//     // Test 2: Add a new variable
//     printf("\nAdding NEW_VAR=123:\n");
//     export_command((char *[]){ "export", "NEW_VAR=123", NULL }, &env, 1);

//     // Test 3: Update an existing variable
//     printf("\nUpdating PATH=/new/path:\n");
//     export_command((char *[]){ "export", "PATH=/new/path", NULL }, &env, 1);

//     // Test 4: Invalid variable name
//     printf("\nInvalid variable name 123VAR=abc:\n");
//     export_command((char *[]){ "export", "123VAR=abc", NULL }, &env, 1);

//     // Test 5: Print updated environment
//     printf("\nUpdated Environment:\n");
//     export_command((char *[]){ "export", NULL }, &env, 1);

//     // Free environment
//     for (int i = 0; env[i]; i++)
//         free(env[i]);
//     free(env);

//     return 0;
// }