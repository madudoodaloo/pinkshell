/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_call_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:42:43 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/20 20:16:51 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_check_access(char *str)
{
	if (access(str, F_OK) && access(str, R_OK))
	{
		free(str);
		return 1;
	}
	free(str);
	return 0;
}

char *path_search(char *str)
{
	int i = 0;
	char *path = get_path();
	char **ret = ft_split(path, ':');
	while(ret && ret[i])
	{
		if (ft_check_access(ft_strjoin(ret[i], str)))
		{
			free_matrix(ret);
			return (ft_strjoin(ret[i], str));
		}
		i++;
	}
	return (ft_strdup(str));
}

int	pipe_error(void)
{
	perror("pipe");
	msh()->exit_status = 1;
	return (-1);
}

void	close_fds(int *fds)
{
	safe_close(fds[0]);
	close(fds[1]);
}

int	fork_error(void)
{
	perror("fork");
	msh()->exit_status = 1;
	return (-1);
}


