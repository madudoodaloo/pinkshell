/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:18:18 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/20 14:05:43 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_home(void)
{
	char	*wd;
	char	*ret;
	int		i;
	int		count_slash;

	i = 0;
	count_slash = 0;
	wd = NULL;
	wd = getcwd(NULL, 0);
	while (wd[i] != '\0')
	{
		if (wd[i] == '/')
			count_slash++;
		if (count_slash == 3)
			break ;
		i++;
	}
	ret = safe_malloc(i + 1);
	ret[i] = '\0';
	while (--i >= 0)
		ret[i] = wd[i];
	free(wd);
	return (ret);
}

/* singleton */
t_msh	*msh(void)
{
	static t_msh	msh;

	return (&msh);
}

t_msh	*init_all(char **envp)
{
	t_msh	*minishell;

	minishell = msh();
	minishell->line = NULL;
	minishell->tokens = NULL;
	minishell->env = get_env(envp);
	minishell->home = get_home();
	minishell->pwd = getcwd(NULL, 0);
	minishell->exec = NULL;
	minishell->exit_status = 0;
	minishell->signaled = false;
	return (msh());
}
