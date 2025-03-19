/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:08:55 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/19 18:30:50 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_pipes(t_token *tokens)
{
	int nr_pipes;
// tenho de dar handle do cenário em que nãao há pipes - o exec tem de a mm mandar malloc the 1
	nr_pipes = 1;
	if (!tokens)
		return (-1);
	while (tokens)
	{
		if (tokens->type == PIPE)
			nr_pipes++;
		tokens = tokens->next;
	}
	return (nr_pipes);
}

char **add_to_matrix(char *content, char **args)
{
	if (!args)
		args =
}

int tokens_to_exec(t_token *token, t_exec *exec)
{
	int i;
	i = 0;
	while (token)
	{
		if (token->type == CMD)
				exec[i]->args = add_to_matrix(token->content, exec[i].args);
		else if (token->type == PIPE)
				;
		else if (token->type == R_APP || token->type == R_OUT) //REVER meter um prefixo antes do file delimiter
				;
		else if (token->type == R_IN || token->type == HERE_DOC)
				;
		if (token->type == CMD)
			token = token->next;
		else if (token->type == PIPE)
		{
			token = token->next;
			i++;
		}
		else
			token = token->next->next;



	}
}


t_exec *init_exec(t_token *tokens);
{
	t_exec	*exec;

	if (!tokens)
		return ERRADO;
	int nr_pipes;
	nr_pipes = count_pipes(tokens); //CHECK IF SYNTAX IS TRULLY WORKING
	exec = (t_exec *)safe_malloc(sizeof(t_exec) * nr_pipes);
	if (tokens_to_exec(tokens, exec) < 0)
		ERRADO; //dar handle desta merda
	//dar free dos tokens todos;
	return (exec);
}


/* rever */
int	set_exec(void)
{
	t_token *tokens;
	t_exec	*exec;

	tokens = msh()->tokens;
	exec = init_exec(tokens);

	return (-1);
}

/* não sei quê multiple pipes */
void	start_execution(void)
{
	return ;
}
