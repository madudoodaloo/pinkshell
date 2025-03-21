/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:36:18 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/21 05:55:52 by msilva-c         ###   ########.fr       */
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
//vai dar skip aos dois strs respetivos à key e ao file da redireção
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
void	exec_r(t_exec *ex, char *key, char *file_name)
{
	ex->out_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ex->out_fd == -1)


}
void	exec_rr(t_exec *ex, char *key, char *file_name)
void	exec_l(t_exec *ex, char *key, char *file_name)
void	exec_ll(t_exec *ex, char *key, char *file_name)




void exec_red2(t_exec *ex, char *key, char *file_name)
{
	if (!strcmp(key, ">"))
		exec_r(ex, key, file_name);
	else if (!strcmp(key, ">>"))
		exec_rr(ex, key, file_name);
	if (!strcmp(key, ">"))
		exec_l(ex, key, file_name);
	else if (!strcmp(key, "<<"))
		exec_ll(ex, key, file_name);
	free(key);
	free(file_name);
}

char **exec_red(t_exec *ex)
{
	char **args;
	int i = 0;

	args = ex->args;
	while (args && args[i])
	{
		if (!ft_strcmp(args[i], "<"))
		{
			ex. = exec_red2(ex, args[i], args[i + 1]);
			args = exred(args, i);
			i = 0;
		}
		else if (!ft_strcmp(args[i], ">"))
		{
			exec_red2(ex, args[i], args[i + 1]);
			args = exred(args, i);
			i = 0;
		}
		else
			i++;
	}
	return args;
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
