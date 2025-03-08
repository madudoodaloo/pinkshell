/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:18:18 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/08 01:37:59 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_msh	*msh(void)
{
	static t_msh	msh;

	return (&msh);
}

t_msh    *init_all(char **envp)
{
    t_msh *minishell;

    minishell = msh();
    minishell->env = init_env(envp);
    minishell->line = (char *)malloc(sizeof(char));
    if (!minishell->line)
        return (NULL);
    minishell->exit = 0;
    minishell->ret = 0;
    minishell->lst_head = (t_token **)malloc(sizeof(t_token *));
    if (!minishell->lst_head)
        return (NULL);
    *(minishell->lst_head) = NULL;
    minishell->ex_tokens = (t_token **)malloc(sizeof(t_token *));
    if (!minishell->ex_tokens)
        return (NULL);
    *(minishell->ex_tokens) = NULL;
    minishell->env = NULL;
    return (minishell);
}
