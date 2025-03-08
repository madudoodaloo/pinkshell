/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:27:31 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/08 02:00:44 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_env *set_env(void)
{

}

static t_env *set_env(void)
{

}

static int	check_env(char **envp)
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

	if (check_env(envp) == 0)
		new = set_env();
	else
	{

	}
	return (new);
}
