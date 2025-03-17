/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:32:36 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/17 19:30:01 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	my_pwd(int fd) // takes in the specific file descriptor to output to, (ex.: 1 for stdin)
{
	char		cwd[MAXPATH];
	const char	*error_msg;

	error_msg = "pwd: ";
	if (getcwd(cwd, sizeof(cwd)) != NULL) // Attempt to get the current working directory
		write(fd, cwd, ft_strlen(cwd)); // If successful, write the dir.path to the specified fd write(fd, "\n", 1);
	else // If getcwd fails, print an error message
	{
		write(fd, error_msg, ft_strlen(error_msg));
		write(fd, error(errno), ft_strlen(strerror(errno)));
		write(fd, "\n", 1);
	}
}
