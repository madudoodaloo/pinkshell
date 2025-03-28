/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:59:02 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/21 02:10:03 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//rever se só tou a chamar isto numa child
void	close_args_fds(t_exec *ex)
{
	int index;

	index = ex->index;
	if (!ex)
		exit(1) ;
	if (ex->is_heredoc)
		close(ex->pipe_doc[0]);
	if (ex->index > 0)
		close(msh()->exec[index-1].pipe_fd[0]);
	if (ex->index < ex->nbr_cmds - 1)
	{
		close_pipe(ex->pipe_fd);
		ex[1].prev_pipe_fd = 0;
	}
	exit(1);
}

static void	excve_perror(char *command)
{
	t_env	*current;
	bool	has_path;

	has_path = false;
	current = msh()->env;
	while (current)
	{
		if (!ft_strncmp(current->var_name, "PATH", 5))
			has_path = true;
		current = current->next;
	}
	write(2, "minishell: ", 11);
	write(2, command, ft_strlen(command));
	if (has_path)
		write(2, ": command not found\n", 20);
	else
		write(2, ": No such file or directory\n", 28);
}

int fix_fd_pipe(t_exec *ex)
{
	if (pipe(ex->pipe_fd) < 0)
		return (-1);
	if (ex->index < ex->nbr_cmds - 1)
		ex[1].prev_pipe_fd = ex->pipe_fd[0];
	//rever se tenho de dar close aqui
	return (1);
}

// rever as merdas dos index + 1 ou - 1
int do_child(t_exec *exec)
{
	if (!exec)
		return (-1);
	if (fix_fd_pipe(exec) < 0)
		return (pipe_error());
	signals_parent();
	exec->pid = fork();
	if (exec->pid < 0)
	{
		close_pipe(exec->pipe_fd);
		return (fork_error());
	}
	if (exec->pid == 0)
	{
		signals_default();
		new_child(exec);
	}
	int i = exec->index;
	if (i > 0 && i + 1 < msh()->exec->nbr_cmds)
		safe_close(msh()->exec[i - 1].pipe_fd[0]);
	if (exec->is_heredoc)
		safe_close(exec->pipe_doc[0]);
	safe_close(exec->pipe_fd[1]);
	if (i + 1 >= msh()->exec->nbr_cmds)
		safe_close(exec->pipe_fd[0]);
	return (1);
}

void new_child(t_exec *ex)
{
	char	**envp;
	char	*path;

	envp = get_matrix_env(msh()->env);
	if (!ex || ex->cmd_invalid)
		close_args_fds(ex);
	if (!ex->args)
		exit(0);
	if (is_builtin(ex->args[0]))
		execute_builtin(ex);
	else
	{
		if (!ft_strchr(ex->args[0], '/'))
			path = path_search(ex->args[0], msh()->env);
		else
			path = ex->args[0];
		execve(path, ex->args, envp);
		excve_perror(ex->args[0]);
	}
	free_matrix(envp);
	exit(127);
}

void exec_single_cmd(t_exec *ex, int in, int out)
{
	if (ex->cmd_invalid)
		return ;
	if (is_builtin(ex->args[0]))
		execute_builtin(ex);
	else
	{
		signals_ignore();
		ex->pid = fork();
		if (ex->pid == -1)
		{
			perror("fork");
			msh()->exit_status = 1;
			return ;
		}
		if (ex->pid == 0)
		{
			signals_default();
			dup2(in, STDIN_FILENO);
			dup2(out, STDOUT_FILENO);
			ft_close(in);
			ft_close(out);
			new_child(ex);
		}
	}
	ft_close(in);
	ft_close(out);
}

void ft_close(int fd)
{
	if (fd > 2)
		close(fd);
}
void execute_loop(t_exec *ex, int in, int out)
{
	int i = 0;
	while (i < msh()->exec->nbr_cmds)
	{
		out = STDOUT_FILENO;
		if (i + 1 < msh()->exec->nbr_cmds)
		{
			pipe(ex[i].pipe_fd);
			out = ex[i].pipe_fd[1];
		}
		if (ex[i].out_fd)
		{
			ft_close(out);
			out = ex[i].out_fd;
		}
		if (ex[i].in_fd)
		{
			ft_close(in);
			in = ex[i].in_fd;
		}
		exec_single_cmd(&ex[i], in, out);
		in = ex[i].pipe_fd[0];
		i++;
	}
}


void start_executing(void)
{
	int i = -1;
	int pid;

	t_exec *ex;
	ex = msh()->exec;
	if (check_redirs(ex) < 0)
		return ;
	ex = msh()->exec;
	if (msh()->exec->nbr_cmds == 1)
		exec_single_cmd(ex, 0, 1);
	else
	{
		pid = fork();
		if (pid == 0)
			execute_loop(ex, STDIN_FILENO, STDOUT_FILENO);
		else
			ft_waitpid(pid);
	}
	i = -1;
	while (++i < msh()->exec->nbr_cmds)
		ft_waitpid(-1);
	main_signals();
}

