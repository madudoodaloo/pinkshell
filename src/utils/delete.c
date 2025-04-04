/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:20:02 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/20 01:14:42 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_struct(t_token **lst_head)
{
	t_token	*current;
	t_token	*counter;
	int		i;

	current = *lst_head;
	counter = *lst_head;
	i = 0;
	while (counter)
	{
		i++;
		counter = counter->next;
	}
	printf("has %d nodes\n", i);
	while (current)
	{
		printf("node: %p\n", current);
		if (current->content != NULL)
			printf("content: %s$ type: %d\n", current->content, current->type);
		else
			printf("content: (null)$\n");
		current = current->next;
	}
}


/*

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		printf
		//printf("matrix[%d] is: %s\n", i, matrix[i]);
		i++;
	}
}
void	print_exec_array()
{
    int	i;

    i = 0;
    while (i < msh()->exec[0].nbr_cmds)
    {
		print_exec_struct(msh()->exec[i]);
		i++;
    }
}

void	print_array(char **array, const char *label)
{
	int	i;

	if (!array)
	{
		printf("%s: (null)\n", label);
		return;
	}
	i = 0;
	while (array[i])
	{
		printf("%s[%d]: %s\n", label, i, array[i]);
		i++;
	}
}

void	print_pipe_fds(int pipe_fd[2])
{
	printf("pipe_fd[0]: %d\n", pipe_fd[0]);
	printf("pipe_fd[1]: %d\n", pipe_fd[1]);
}

void	print_exec_struct(t_exec *exec)
{
	if (!exec)
	{
		printf("exec struct is NULL\n");
		return;
	}
	int i = 0;
	while (i < cmds)
	print_array(exec->redir_in, "redir_in");
	print_array(exec->redir_out, "redir_out");
	//print_matrix(exec->args);
	printf("nbr_cmds: %d\n", exec->nbr_cmds);
	print_pipe_fds(exec->pipe_fd);
	printf("in_fd: %d\n", exec->in_fd);
	printf("out_fd: %d\n", exec->out_fd);
	printf("is_heredoc: %s\n", exec->is_heredoc ? "true" : "false");
	print_array(exec->envp, "envp");
	printf("cmd_invalid: %s\n", exec->cmd_invalid ? "true" : "false");
} */
