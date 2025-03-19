/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:27:31 by msilva-c          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/19 13:52:13 by msilva-c         ###   ########.fr       */
=======
/*   Updated: 2025/03/19 11:49:11 by marianamest      ###   ########.fr       */
>>>>>>> 0ffbed88cfd476024dcdc0e6539da8f57235453d
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	dup_var(t_env *start, t_env *new)
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

// rever line 37 se deve ser || or &&
void	var_add_back(t_env *start, t_env *new)
{
	t_env	*temp;
	t_env	*end;

	end = NULL;
    temp = start;
    if (new->valid == false && dup_var(temp, end))
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
        end->next = new;
}

t_env	*create_var(char *str)
{
	t_env	*new;
	int		i;

	i = 0;
	new = NULL;
	new = (t_env *)safe_malloc(sizeof(t_env));
	new->var = ft_strdup(str);
	new->valid = false;
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

int	check_env(char **envp)
{
	int	i;

	i = 0;
	if (!envp || !*envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

t_env	*get_env(char **envp)
{
	int		i;
	t_env	*new;
	t_env	*temp;

	i = 0;
	new = NULL;
	temp = NULL;
	if (check_env(envp) == 0)
		new = empty_env();
	else
	{
		while (envp[i])
		{
			temp = create_var(envp[i]);
			if (i > 0)
				var_add_back(new, temp);
			i++;
		}
	}
	return (new);
}
