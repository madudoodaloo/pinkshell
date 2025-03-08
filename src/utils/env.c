/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:01:39 by msilva-c          #+#    #+#             */
/*   Updated: 2024/11/22 04:52:32 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char **copy_matrix(char **src)
{
    char **dst;
    int i = 0;

    while (src[i] != NULL)
        i++;
    dst = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dst)
		return (NULL);
    i = -1;
    while (src[++i])
        dst[i] = ft_strdup(src[i]);
    dst[i] = NULL;
    return (dst);
}
