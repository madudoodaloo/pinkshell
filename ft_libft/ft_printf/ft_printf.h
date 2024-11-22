/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skioridi <skioridi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:52:12 by skioridi          #+#    #+#             */
/*   Updated: 2023/12/06 22:23:10 by skioridi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEXL "0123456789ABCDEF"
# define HEXS "0123456789abcdef"

int		ft_printf(const char *s, ...);
void	ft_conversions(char c, va_list ap, int *len);
void	ft_putlchar(char c, int *len);
void	ft_putlnbr(long int nb, int *len);
void	ft_putlhex(long unsigned int nb, char *hex, int *len);
void	ft_callputlhex(unsigned int nb, char *hex, int *len);
void	ft_putlstr(char *s, int *len);
void	ft_putladd(unsigned long add, int *len);
void	ft_putluns(unsigned int nb, int *len);

#endif