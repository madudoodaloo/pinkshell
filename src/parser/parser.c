/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:32:58 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/19 08:07:01 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parser(void)
{
	if (!check_quotes(msh()->line))
		return (0);
	if (!tokenizer())
		return (0);
	expander(msh()->tokens);
	if (!check_syntax(msh()->tokens))
		return (0);

	//dar set da struct para a exec
	return (1);
}
