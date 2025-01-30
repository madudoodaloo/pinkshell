/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:45:23 by marianamest       #+#    #+#             */
/*   Updated: 2025/01/30 17:46:00 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void handle_ctrl_d(char *line)
{
    if (line == NULL)
    {
        write(1, "exit\n", 5);
        free(line);
        exit(0);
    }
}
