/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 07:08:43 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/15 17:08:19 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//rever
bool	parse_quotes(const char *input)
{
	int		i;
	bool	in_quote;
	bool	in_squote;

	i = 0;
	in_quote = false;
	in_squote = false;
	while (input[i] != '\0')
	{
		if (input[i] == '\"' && !in_squote)
			in_quote = !in_quote;
		else if (input[i] == '\'' && !in_quote)
			in_squote = !in_squote;
		i++;
	}
	if (!in_quote && !in_squote)
		return (true);
	return (false);
}

bool	in_quote(const char *input, int index)
{
	int		i;
	bool	q_flag;
	bool	s_flag;

	i = 0;
	q_flag = false;
	s_flag = false;
	while (i < index && input[i] != '\0')
	{
		if (input[i] == '\"' && !s_flag)
			q_flag = !q_flag;
		else if (input[i] == '\'' && !q_flag)
			s_flag = !s_flag;
		i++;
	}
	if (!q_flag && !s_flag)
		return (false);
	return (true);
}

bool	in_squote(const char *input, int index)
{
	int		i;
	bool	q_flag;
	bool	s_flag;

	i = 0;
	q_flag = false;
	s_flag = false;
	while (i < index && input[i] != '\0')
	{
		if (input[i] == '\"' && !s_flag)
			q_flag = !q_flag;
		else if (input[i] == '\'' && !q_flag)
			s_flag = !s_flag;
		i++;
	}
	if (!q_flag && !s_flag)
		return (false);
	if (!q_flag && s_flag)
		return (true);
	return (false);
}

