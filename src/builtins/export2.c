/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:47:08 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/16 23:46:09 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"


void	add_or_update_env_var(char ***env, const char *var)
{
	char	*equals;
	int		name_len;
	int		index;

	equals = ft_strchr(var, '=');
	if (equals)
		name_len = equals - var;
	else
		name_len = ft_strlen(var);
	index = find_var_index(*env, var, name_len);
	if (index != -1)
	{
		free((*env)[index]);
		(*env)[index] = ft_strdup(var);
		if (!(*env)[index])
		{
			perror("strdup failed");
			exit(EXIT_FAILURE);
		}
	}
	else
		add_new_var(env, var);
}

void	print_sorted_env(char **env, int fd)
{
	int	env_size;
	int	i;
	int	j;

	env_size = 0;
	while (env[env_size])
		env_size++;
	i = 0;
	while (i < env_size - 1)
	{
		j = i + 1;
		while (j < env_size)
		{
			if (ft_strcmp(env[i], env[j]) > 0)
				ft_swap(&env[i], &env[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (env[i])
	{
		format_export_var(env[i]);
		i++;
	}
}

void export_command(char **args, char ***env, int fd)
{
	int i;
    if (!args[1])
        print_sorted_env(*env, fd);
    else
    {
        i = 1;
        while (args[i])
        {
            if (!parse_export(args[i]))
                printf("export: '%s': not a valid identifier\n", args[i]);
            else
            {
                add_or_update_env_var(env, args[i]);
                print_sorted_env(*env, fd);
            }
            i++;
        }
    }
}
