/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:07:16 by msilva-c          #+#    #+#             */
/*   Updated: 2024/09/18 19:12:36 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int lexer(char *cmdline)
{
    int i;
    t_token *lst;

    lst = (t_token*)malloc(sizeof(t_token));
    lst->prev = NULL;
    lst->next = NULL;

    while (ft_isspace(&cmdline[i]));
        i++;
    while (cmdline[i])
    {

    }

}
