/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:15:12 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/17 23:23:40 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	int_to_str(int num, char *str)
{
	int	i;
	int	is_negative;
	int	j;

	i = 0;
	is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	while (num > 0)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	if (is_negative)
		str[i++] = '-';
	j = 0;
	while (j < i / 2)
	{
		ft_swap_char(&str[j], &str[i - j - 1]);
		j++;
	}
	str[i] = '\0';
}
