/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:32:58 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 17:38:50 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parser(t_msh *msh)
{
	if (!check_quotes(msh->line, -1))
		return (-1);
	if (!tokenizer(msh))
		return (-1);
	expander(msh->tokens);
	//expander(msh->tokens);
	//dar set da struct para a exec
	return (0);
}
