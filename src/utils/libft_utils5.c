/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:44:25 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/20 21:00:44 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_counter(char const *str, char c)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	while (str[++i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			word++;
	}
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		i;
	int		start;
	int		size;

	split = (char **)safe_malloc(sizeof(char *) * (ft_counter(str, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	start = -1;
	while (str[++start])
	{
		size = 0;
		while (str[start + size] != c && str[start + size] != '\0')
			size++;
		if ((str[start + size] == c && size > 0) || str[start + size] == '\0')
		{
			split[i++] = ft_substr(str, start, size);
			if (str[start + size] == '\0')
				break ;
			start += size;
		}
	}
	split[i] = NULL;
	return (split);
}

static int	ft_intmin(char *str)
{
	int	i;

	str[1] = '2';
	i = -147483648;
	return (i);
}

static size_t	ft_digits(int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = ft_digits(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
			n = ft_intmin(str);
		n = -n;
	}
	str[size] = '\0';
	while (n > 0)
	{
		str[--size] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

char	**copy_matrix(char **src)
{
	char	**dst;
	int		i;

	i = 0;
	while (src[i] != NULL)
		i++;
	dst = (char **)safe_malloc(sizeof(char *) * (i + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (src[++i])
		dst[i] = ft_strdup(src[i]);
	dst[i] = NULL;
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	size_src;
	size_t	size_dst;
	size_t	i;

	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	if (!n)
		return (size_src);
	if (size_dst >= n)
		return (n + size_src);
	i = 0;
	while (i < (n - size_dst - 1) && src[i])
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_src + size_dst);
}
