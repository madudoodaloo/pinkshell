/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:44:20 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 10:46:20 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ignore_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && in_squote(str, i))
			str[i] = TEMP_DOLLAR;
		else if (str[i] == '$' && str[i + 1] == 34 && check_quotes(str, i))
			str[i] = TEMP_DOLLAR;
		else if (str[i] == '$' && str[i + 1] == 39 && check_quotes(str, i + 1))
			str[i] = TEMP_DOLLAR;
		else if (str[i] == '$' && !str[i + 1] && i > 0 && str[i - 1] != '$')
			str[i] = TEMP_DOLLAR;
		i++;
	}
}

void	put_dollar_back(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == TEMP_DOLLAR)
			str[i] = '$';
	}
}
