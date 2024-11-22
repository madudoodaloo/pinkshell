/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:07:40 by marianamest       #+#    #+#             */
/*   Updated: 2024/11/11 15:30:50 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_flag_n(char *str)
{
	return (str[0] == '-' && str[1] == 'n' && str[2] == '\0'); // if there's a "-n" flag
}

void	print_args(char **args, int start_index) // prints each arg and checks if there's a following one
{
	int i;

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

	start_index = 1; // from where print_args will start printing
	newline = 1;
	if (args[1] && is_flag_n(args[1]))
	{
		newline = 0;
		start_index++;
	}
	print_args(args, start_index);
	if (newline) // print newline if no `-n` flag was provided
		printf("\n");
}
