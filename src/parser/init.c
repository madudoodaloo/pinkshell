/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:18:18 by msilva-c          #+#    #+#             */
/*   Updated: 2024/11/22 04:52:32 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_msh    *init_all(t_msh *msh)
{
    msh->line = (char *)malloc(sizeof(char));
    if (!msh->line)
        return (NULL);
    msh->exit = 0;
    msh->ret = 0;
    msh->lst_head = (t_token **)malloc(sizeof(t_token *));
    if (!msh->lst_head)
        return (NULL);
    //acho que a lista está mal iniciada, tem de ser sizeof(t_token) * nr de tokens a serem criados.
    *(msh->lst_head) = NULL;
    msh->env = NULL;
    return (msh);
}
