/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:18:18 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/08 01:06:32 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_msh	*msh(void)
{
	static t_msh	*msh;

	return (&msh);
}

t_msh    *init_all(t_msh *msh)
{
    t_msh *msh;

    msh = msh();
    msh->line = (char *)malloc(sizeof(char));
    if (!msh->line)
        return (NULL);
    msh->exit = 0;
    msh->ret = 0;
    msh->lst_head = (t_token **)malloc(sizeof(t_token *));
    if (!msh->lst_head)
        return (NULL);
    *(msh->lst_head) = NULL;
    msh->ex_tokens = (t_token **)malloc(sizeof(t_token *));
    if (!msh->ex_tokens)
        return (NULL);
    *(msh->ex_tokens) = NULL;
    msh->env = NULL;
    return (msh);
}
