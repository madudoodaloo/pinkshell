/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:38:25 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 02:11:29 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_and_exit(t_msh *msh)
{
	if (!msh)
		return ;
	if (msh->line)
		free(msh->line);
	if (msh->tokens)
		free_token_list(msh->tokens);
	if (msh->pwd)
		free(msh->pwd);
    if (msh->exec)
        free_pipex_list(msh->exec);
    if (msh->env)
        free_env_list(msh->env);
	if (msh->home)
		free(msh->home);
	clear_history();
}
