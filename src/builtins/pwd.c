/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:32:36 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/17 21:39:00 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	my_pwd(int fd)
{
	char		cwd[MAXPATH];
	const char	*error_msg;

	error_msg = "pwd: ";
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		write(fd, cwd, ft_strlen(cwd));
	else
	{
		write(fd, error_msg, ft_strlen(error_msg));
		write(fd, error(errno), ft_strlen(strerror(errno)));
		write(fd, "\n", 1);
	}
}
