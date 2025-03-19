/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 07:28:19 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/19 16:56:51 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	syntax_red(t_token *token)
{
	if (token->next->type != CMD)
		return (error_redir(token));
	else if (!token->next)
		return (error_redir(token));
	return (1);
}

int	syntax_pipe(t_token *token)
{
	if (!token->next)
		return (error_pipe());
	else if (!token->prev)
		return (error_pipe());
	else if (token->next->type == PIPE)
		return (error_pipe());
	return (1);
}

int	error_redir(t_token *token)
{
	printf("inside error redir\n");
	if (!token || !token->content || !token->content[0])
	{
		ft_put_str_fd("error near redirections\n", 2);
		return (0);
	}
	if (!token->prev)
	{
<<<<<<< HEAD
		write(2, "error near newline\n", 19);
=======
		ft_put_str_fd("error near newline\n", 2);
>>>>>>> ebc20cefbf185e866de25b0816340fea00465b87
		return (0);
	}
	write(2, "error near \"", 12);
	write(2, &token->content[0], 1);
	write(2, "\"\n", 2);
	return (0);
}

int	error_pipe(void)
{
	printf("inside error pipe\n");
	ft_put_str_fd("unexpected error near \"|\"\n", 2);
	return (0);
}

int	check_syntax(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (temp->type == R_OUT || temp->type == R_IN || temp->type == R_APP
			|| temp->type == HERE_DOC)
		{
			if (!syntax_red(temp))
				return (0);
		}
		else if (temp->type == PIPE)
		{
			if (!syntax_pipe(temp))
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}
