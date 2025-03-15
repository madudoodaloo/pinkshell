/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 23:10:50 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/28 00:26:36 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlstr(char *s, int *len)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	i = -1;
	while (s[++i] != '\0')
		ft_putlchar(s[i], len);
}

void	ft_putladd(unsigned long add, int *len)
{
	if (!add)
		ft_putlstr("(nil)", len);
	else
	{
		if (add < 16)
		{
			ft_putlstr("0x", len);
			ft_putlchar(HEXS[add], len);
			return ;
		}
		ft_putladd(add / 16, len);
		ft_putlchar(HEXS[add % 16], len);
	}
}
