/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:36:18 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/20 23:40:18 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int size_args(char **args)
{
	int size;

	size = 0;
	if (!args || !args[0])
		return (0);
	while(args[size])
		size++;
	return size;
}

char **exred(char **args, int i)
{
	char **new;
	int size;
	int	j;
	int	k;

	size = size_args(args);
	new = safe_malloc((size + 1) * sizeof(char *));
	j = 0;
	k = 0;
	while(k < size && args[k])
	{
		if (k == i)
			k += 2;
		else
			new[j++] = args[k++];
	}
	return (new);
}
void exec_red2(t_exec *ex, char *key, char *value)
{
	printf("r: %s - %s\n", key, value);
	free(key);
	free(value);
}

char **exec_red(t_exec *ex)
{
	char **agrs;
	int i = 0;

	agrs = ex->args;
	while (agrs && agrs[i])
	{
		if (!ft_strcmp(agrs[i], "<"))
		{
			exec_red2(ex, agrs[i], agrs[i + 1]);
			agrs = exred(agrs, i);
			i = 0;
		}
		else
			i++;
	}
	return agrs;
}

int	check_redirs(t_exec *ex)
{
	int i = 0;
	while (i < msh()->exec->nbr_cmds)
	{
		ex[i].args = exec_red(&ex[i]);
		i++;
	}
	return (1);
}
//RESCREVER ESTA MERDA
void do_input_redir(t_exec *ex)
{
	if (ex->index > 0)
	{
		if (!ex->redir_in)
			dup2(ex->prev_pipe_fd, 0);
		safe_close(ex->prev_pipe_fd);
	}
	if (ex->redir_in && ex->redir_in[0])
	{
		if (ex->is_heredoc)
		{
			dup2(ex->pipe_doc[0], 0);
			safe_close(ex->pipe_doc[0]);
		}
		else
		{
			dup2(ex->in_fd, 0);
			safe_close(ex->in_fd);
		}
	}
}
//RESCREVER ESTA MERDA
void do_output_redir(t_exec *ex)
{
	if (ex->index < ex->nbr_cmds - 1 && !ex->redir_out)
		dup2(ex->pipe_fd[1], 0);
	if (ex->redir_out)
		dup2(ex->out_fd, 0);
	safe_close(ex->prev_pipe_fd);
}
