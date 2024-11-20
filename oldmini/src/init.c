/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:18:18 by msilva-c          #+#    #+#             */
/*   Updated: 2024/09/23 14:05:29 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_msh    *init_all(t_msh *msh)
{
    msh->line = (char *)malloc(sizeof(char));
    msh->exit = 0;
    msh->ret = 0;
    msh->lst_head = (t_token **)malloc(sizeof(t_token *));
    //acho que a lista está mal iniciada, tem de ser sizeof(t_token) * nr de tokens a serem criados.
    *(msh->lst_head) = NULL;
    msh->env = NULL;
    return (msh);
}
