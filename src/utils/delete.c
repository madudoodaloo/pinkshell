/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:20:02 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/16 19:28:48 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_struct(t_token **lst_head)
{
	t_token *current;
	t_token *counter;


	current = *lst_head;
	counter = *lst_head;
	int i = 0;
	while (counter)
	{
		i++;
		counter = counter->next;
	}
	printf("has %d nodes\n", i);
	while (current)
	{
			printf("node: %p\n", current);
			if (current->content != NULL)
				printf("content: %s$ type: %d\n", current->content, current->type);
			else
				printf("content: (null)$\n");
			current = current->next;
	}
}

char **copy_matrix(char **src)
{
    char **dst;
    int i = 0;

    while (src[i] != NULL)
        i++;
    dst = (char **)safe_malloc(sizeof(char *) * (i + 1));
	if (!dst)
		return (NULL);
    i = -1;
    while (src[++i])
        dst[i] = ft_strdup(src[i]);
    dst[i] = NULL;
    return (dst);
}

void    print_matrix(char **matrix)
{
    int i;

    i = 0;
    while (matrix[i])
    {
        ft_printf("matrix[%d] is: %s\n", i, matrix[i]);
        i++;
    }
}
