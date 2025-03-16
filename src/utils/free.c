/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:41 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/16 22:54:54 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_token_list(t_token *tokens)
{
    t_token	*current;
	t_token	*temp;

	if (!tokens)
		return ;
	current = tokens;
	temp = tokens;
	while (current)
	{
		temp = current->next;
        if (current)
        {
            if (current->content)
                free(current->content);
            free(current);
        }
		current = temp;
	}
}

void	free_var(t_env *var)
{
	if (!var)
		return ;
	if (var->var)
		free (var->var);
	if (var->var_name)
		free (var->var_name);
	if (var->var_value)
		free (var->var_value);
	free (var);
}

void    free_env(t_env *env)
{
    t_env *temp;

    if (!env)
        return ;
    while (env)
    {
        temp = env->next;
        free_var(env);
        env = temp;
    }
}

void free_matrix(char **matrix)
{
    int i;

    if (!matrix)
        return;
    i = 0;
    while (matrix[i])
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void free_pipex_list(t_pipex *pipex)
{
    return ;
}


void    free_and_exit(t_msh *msh)
{
	if (!msh)
		return ;
    if (msh->line)
        free (msh->line);
    if (msh->tokens)
        free_token_list(msh->tokens);
	if (msh->pwd)
		free(msh->pwd);
    if (msh->pipex)
        free_pipex_list(msh->pipex);
    if (msh->env)
        free_env_list(msh->env);
	if (msh->home)
		free(msh->home);
	clear_history();
}
