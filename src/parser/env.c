/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:27:31 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 10:47:28 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int dup_var(t_env *start, t_env *new)
{
	t_env	*temp;

	temp = start;
	while (temp)
	{
		if (!ft_strcmp(temp->var_name, new->var_name))
			return (1);
		temp = temp->next;
	}
	return (0);

}

//rever line 37 se deve ser || or &&
void	var_add_back(t_env *start, t_env *new)
{
    t_env	*temp;
    t_env	*end;

    temp = start;
    if (new->valid == false || dup_var(temp, end))
        return ;
    while (temp)
    {
        if (!ft_strcmp(temp->var_name, new->var_name))
        {
            free(temp->var_value);
            temp->var_value = ft_strdup(new->var_value);
            temp->valid = true;
            free_var(new);
            return ;
        }
        end = temp;
        temp = temp->next;
    }
    if (end)
    {
        end->next = new;
    }
}

t_env	*create_var(char *str)
{
	t_env *new;
	int i;

	i = 0;
	new = (t_env *)safe_malloc(sizeof(t_env));
	new->var = ft_strdup(str);
	while (str[i] && str[i] != '=')
		i++;
	new->var_name = ft_substr(str, 0, i);
	if (str[i] == '=')
		new->var_value = ft_strdup(&str[i + 1]);
	else
		new->var_value = ft_strdup("");
	if (str[i] == '=')
		new->valid = true;
	new->next = NULL;
	return (new);
}

char **get_default_env(void)
{
	char **default_env = safe_malloc(sizeof(char *) * 5);
	default_env[0] = ft_strdup("LS_COLORS=");
	default_env[1] = ft_strdup("SHLVL=1");
	default_env[2] = ft_strdup("PATH=/usr/local/bin:"
		"/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin");
	default_env[3] = ft_strdup("_=/usr/bin/env");
	default_env[4] = NULL;
}

t_env *empty_env(void)
{
	t_env	*start;
	t_env	*temp;
	char	**default_env;
	int	i;
	char	cwd[4096];

	i= 0;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd"); //rever este handle de erros
		exit(1);
	}
	start = create_var("PWD=");
	free(start->var_value);
	start->var_value = ft_strdup(cwd);
	while (default_env && default_env[i])
	{
		temp = create_var(default_env[i++]);
		var_add_back(start, temp);
		free(temp);
	}
	if (default_env)
		free_matrix(default_env);
	return (start);
}

int	check_env(char **envp)
{
	int i = 0;
	if (!envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

t_env	*get_env(char **envp)
{
	int i;
	t_env	*new;
	t_env	*temp;

	i = -1;
	if (check_env(envp) == 0)
		new = empty_env();
	else
	{
		while (envp[++i])
		{
			temp = create_var(envp[i]);
			if (i > 0)
				add_var_back(new, temp);
		}
	}
	return (new);
}

t_env	*env_dup(t_env *env)
{
	t_env	*new;
	t_env	*temp;

	if (!env)
		return (NULL);
	new = create_var(env->var);
	temp = env->next;
	while (temp)
	{
		var_add_back(new, init_var(temp->var));
		temp = temp->next;
	}
	return (new);
}
