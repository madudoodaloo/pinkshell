/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:07:40 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 14:06:44 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_flag_n(char *str)
{
	return (str[0] == '-' && str[1] == 'n' && str[2] == '\0');
}

void	print_args(char **args, int start_index)
{
	int	i;

	i = start_index;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
}

void	run_echo(char **args)
{
	int	start_index;
	int	newline;

	start_index = 1;
	newline = 1;
	if (args[1] && is_flag_n(args[1]))
	{
		newline = 0;
		start_index++;
	}
	print_args(args, start_index);
	if (newline)
		printf("\n");
}
