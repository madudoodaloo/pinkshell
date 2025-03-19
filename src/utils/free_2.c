/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:38:25 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/19 15:36:24 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_and_exit(void)
{
	t_msh	*m;

	m = (msh());
	if (!m)
		return ;
	clear_history();
	if (m->line)
		free(m->line);
	if (m->tokens)
		free_tokens(m->tokens);
	if (m->pwd)
		free(m->pwd);
	if (m->exec)
		free_exec(m->exec);
	if (m->env)
		free_env(m->env);
	if (m->home)
		free(m->home);
}
