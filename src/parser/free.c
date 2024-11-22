/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:41 by msilva-c          #+#    #+#             */
/*   Updated: 2024/11/22 10:44:49 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}


void    free_and_exit(t_msh *msh)
{
    t_token *temp;

    if (msh->line)
    {
        free(msh->line);
    }
    if (msh->lst_head)
    {
        if (*msh->lst_head)
        {
            printf("*msh->lst_head is %p\n", *msh->lst_head);
            ft_tknclear(msh->lst_head);
        }
        free(msh->lst_head);
    }
/*     if (msh->ex_tokens)
    {
        if (*msh->ex_tokens)
        {
            printf("*msh->lst_head is %p\n", *msh->lst_head);
            ft_tknclear(msh->ex_tokens);
        }
        free(msh->ex_tokens);
    } */
    free(msh->ex_tokens);
    if (msh->env)
    {
        ft_free_matrix(msh->env);
    }
    return ;
}
