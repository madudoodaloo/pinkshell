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
	if (!check_redirs(ex) < 0)
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