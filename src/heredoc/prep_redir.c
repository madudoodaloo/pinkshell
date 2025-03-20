/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:29:52 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 16:11:49 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	prep_in_redir(char **in_redirs, t_exec *exec, int k)
{
	int	i;

	(void)in_redirs;
	(void)k;
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
