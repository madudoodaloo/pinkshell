/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:43:34 by skioridi          #+#    #+#             */
/*   Updated: 2023/04/17 17:52:24 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	finddigits(long n)
{
	int	d;

	d = 1;
	if (n < 0)
		d++;
	while ((n / 10 > 0) || (n / 10 < 0))
	{
		d++;
		n /= 10;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	char	*new;
	long	ln;
	int		dgtno;

	ln = n;
	dgtno = finddigits(ln);
	new = malloc(dgtno + 1);
	if (!new)
		return (NULL);
	new[dgtno] = '\0';
	if (ln < 0)
	{
		new[0] = '-';
		ln *= -1;
	}
	if (ln == 0)
		new[0] = '0';
	while (ln > 0)
	{
		new[dgtno - 1] = (ln % 10) + '0';
		ln /= 10;
		dgtno--;
	}
	return (new);
}
