/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:29:52 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 21:09:31 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//rever se todos os prefixos estão iguais
void open_outfiles_loop(char **out, t_exec *ex)
{
	int i = 0;
	while (out[i])
	{
		safe_close(ex->out_fd);
		if (!strncmp(out[i], "APP", 3))
			ex->out_fd = open(out[i] + 3, O_CREAT, O_APPEND);
		else if (!strncmp(out[i], "STD", 3))
			ex->out_fd = open(out[i] + 3, O_CREAT, O_TRUNC);
		i++;
	}
}

int	prep_out_redir(t_exec *exec)
{
	int	i;

	i = 0;
	while (i < exec[i].nbr_cmds)
	{
		if (exec[i].redir_out != NULL)
		{
			open_outfiles_loop(exec[i].redir_out, exec);
		}
		i++;
	}
	return (1);

}

int	prep_in_redir(t_exec *exec)
{
	int	i;

	i = 0;
	while (i < exec[i].nbr_cmds)
	{
		if (exec[i].redir_in != NULL)
		{
			is_final_heredoc(exec[i].redir_in, exec, i);
			doc_loop(exec[i].redir_in, exec, i);
		}
		i++;
	}
	i = 0;
	while (i < exec[i].nbr_cmds)
	{
		open_infile_loop(exec[i].redir_in, exec, i);
		i++;
	}
	return (0);
}

int	doc_loop(char **in_redirs, t_exec *exec, int k) // rever :  doc pipe check
{
	int	i;

	i = 0;
	while (in_redirs[i] != NULL)
	{
		if (!ft_strncmp(in_redirs[i], "app:", 4))
		{
			safe_close(exec[k].pipe_fd[0]);
			if (run_doc(in_redirs[i] + 4, exec, k) < 0)
				return (-1);
		}
		i++;
	}
	if (!is_final_heredoc(in_redirs, exec, k))
		close(exec[k].pipe_fd[0]);
	return (0);
}

int	open_infile_loop(char **in_redirs, t_exec *exec, int k)
{
	int	i;
	//int	fd;

	i = 0;
	while (in_redirs[i] != NULL)
	{
		if (ft_strncmp(in_redirs[i], "app:", 4) != 0)
			if (!check_and_open_file(in_redirs[i] + 4))
				exec[k].cmd_invalid = true;
	}
	if (exec[k].is_heredoc)
		safe_close(exec->in_fd);
	return (0);
}

int	is_final_heredoc(char **in_redirs, t_exec *exec, int k)
{
	int	i;
	int	last_heredoc_index;

	last_heredoc_index = -1;
	i = 0;
	while (in_redirs[i] != NULL)
	{
		if (ft_strncmp(in_redirs[i], "app:", 4) == 0)
		{
			last_heredoc_index = i;
		}
		i++;
	}
	if (last_heredoc_index != -1 && last_heredoc_index == i - 1)
	{
		exec[k].is_heredoc = true;
		return (1);
	}
	exec[k].is_heredoc = false;
	return (0);
}

bool	check_and_open_file(char *file_name)
{
	int	fd;

	if (file_name == NULL || *file_name == '\0')
	{
		ft_put_str_fd("Error: File name is empty\n", STDERR_FILENO);
		return (false);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_put_str_fd("Error opening file: %s\n", STDERR_FILENO);
		return (false);
	}
	close(fd);
	return (true);
}
