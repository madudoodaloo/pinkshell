/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:44:59 by skioridi          #+#    #+#             */
/*   Updated: 2023/05/02 18:08:36 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversions(char c, va_list ap, int *len)
{
	if (c == 'c')
		ft_putlchar(va_arg(ap, int), len);
	if (c == 's')
		ft_putlstr(va_arg(ap, char *), len);
	if (c == 'p')
		ft_putladd(va_arg(ap, unsigned long), len);
	if (c == 'd')
		ft_putlnbr(va_arg(ap, int), len);
	if (c == 'i')
		ft_putlnbr(va_arg(ap, int), len);
	if (c == 'u')
		ft_putluns(va_arg(ap, unsigned int), len);
	if (c == 'x')
		ft_callputlhex(va_arg(ap, unsigned int), HEXS, len);
	if (c == 'X')
		ft_callputlhex(va_arg(ap, unsigned int), HEXL, len);
	if (c == '%')
		ft_putlchar('%', len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		len;

	len = 0;
	va_start(ap, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
			ft_conversions(s[++i], ap, &len);
		else
			ft_putlchar(s[i], &len);
	}
	va_end(ap);
	return (len);
}
