/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:41 by msilva-c          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/18 00:56:11 by msilva-c         ###   ########.fr       */
=======
/*   Updated: 2025/03/17 23:24:56 by marianamest      ###   ########.fr       */
>>>>>>> 2ed0a882eb6738b777b30c67a7bec9ab831ab186
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		free(var->var);
	if (var->var_name)
		free(var->var_name);
	if (var->var_value)
		free(var->var_value);
	free(var);
}

void	free_env(t_env *env)
{
	t_env	*temp;

	if (!env)
		return ;
	while (env)
	{
		temp = env->next;
		free_var(env);
		env = temp;
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void free_pipex_list(t_exec *exec)
{
	return ;
}

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
<<<<<<< HEAD
    if (msh->exec)
        free_pipex_list(msh->exec);
    if (msh->env)
        free_env_list(msh->env);
=======
	if (msh->pipex)
		free_pipex_list(msh->pipex);
	if (msh->env)
		free_env_list(msh->env);
>>>>>>> 2ed0a882eb6738b777b30c67a7bec9ab831ab186
	if (msh->home)
		free(msh->home);
	clear_history();
}
