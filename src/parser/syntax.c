/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 07:28:19 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/19 08:11:09 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	syntax_red(t_token *token)
{
	if (token->next->type != CMD)
		return (0);
	else if (!token->next)
		return (0);
	return (1);
}

int	syntax_pipe(t_token *token)
{
	if (!token->next)
		return (0);
	else if (!token->prev)
		return (0);
	else if (token->next->type == PIPE)
		return (0);
	return (1);
}

int	error_redir(t_token *token)
{
	if (!token || !token->content || !token->content[0])
	{
		ft_put_str_fd("error near redirections\n", 2);
		return (0);
	}
	if (!token->prev)
	{
		write (2, "error near newline\n", 19);
		return (0);
	}
	write(2, "error near \"", 12);
	write(2, &token->content[0], 1);
	write(2, "\"\n", 2);
	return (0);
}

int	error_pipe(void)
{
	ft_put_str_fd("unexpected error near \"|\"\n", 2);
	return (0);
}

int	check_syntax(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (temp->type == R_OUT || temp->type == R_IN
			|| temp->type == R_APP || temp->type == HERE_DOC)
		{
			if (!syntax_red(temp))
				return (error_redir(temp));
		}
		else if (temp->type == PIPE)
		{
			if (!syntax_pipe(temp))
				return (error_pipe());
		}
		temp = temp->next;
	}
	return (1);
}
