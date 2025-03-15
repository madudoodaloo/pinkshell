/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:41 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/15 19:43:08 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    free_struct(t_token **head)
{
    t_token *temp;

    while (*head)
    {
        temp = (*head)->next;
        if ((*head)->content)
            free((*head)->content);
        free(*head);
        *head = temp;
    }
    free(*head);
}

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
            ft_tknclear(msh->lst_head);
        free(msh->lst_head);
    }
    if (msh->ex_tokens)
    {
        if (*msh->ex_tokens)
            ft_tknclear(msh->ex_tokens);
        free(msh->ex_tokens);
    }
    if (msh->env)
    {
        ft_free_matrix(msh->env);
    }
    return ;
}

void	free_all(void *strut)
{
	if (strut)
		free(strut);
}
