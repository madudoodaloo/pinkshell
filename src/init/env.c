/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:27:31 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/08 15:10:17 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*add_var(char *str)
{
	t_env *new;
	int i;

	i = 0;
	new = (t_env *)safe_malloc(sizeof(t_env));
	new->var = ft_strdup(str);
	while (str[i] && str[i] != '=')
	i++;
	// rever o ft_substr
	new->var_name = ft_substr(str, 0, i);
	if (str[i] == '=')
		new->var_value = ft_strdup(&str[i + 1]);
	else
		new->var_value = ft_strdup("");
	if (str[i] == '=')
		new->valid = true;
	else
		new->valid = false;
	new->next = NULL;
	return (new);
}

t_env *copy_env(void)
{

}

t_env *empty_env(void)
{

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
			temp = add_var(envp[i]);
			if (i > 0)
				add_var_back(new, temp);
		}
	}
	return (new);
}
