/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 04:54:10 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/22 00:03:50 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	copy_quote(char *dest, int i_dest, char *src, int i_src)
{
	int	i;
	int	j;

	i = i_src;
	j = i_dest;
	if (src[i] == '\'')
	{
		i++;
		while (src[i] != '\'' && src[i] != '\0')
			dest[j++] = src[i++];
	}
	else if (src[i] == '\"')
	{
		i++;
		while (src[i] != '\"' && src[i] != '\0')
			dest[j++] = src[i++];
	}
}

int	rm_strlen(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_isquote(str[i]))
		{
			len -= 2;
			i += skip_quotes(str, i) - 1;
		}
	}
	return (len);
}

void rm_util(char *str, int i, char *new, int i_new)
{
	while (str[i])
	{
		if (ft_isquote(str[i]))
		{
			copy_quote(str, i, new, i_new);
			i_new = i_new + skip_quotes(str, i);
		}
	}
}


char *rm_quote(char *str)
{
	char *new;
	int i;
	int i_new;

	i = -1;
	i_new = 0;
	if (rm_strlen(str) == ft_strlen(str))
		return (str);
	new = (char *)safe_malloc(rm_strlen(str) + 1 + 1);
	if(!rm_strlen(str))
		new[0] = '\0';
	else
		rm_util(str, i + 1, new, i_new);
	free(str);
	return (new);
}
void	rm_quotes_exec(t_exec	*exec)
{
	int		i;
	int index;

	i = -1;
	index = 0;
	if (!exec)
		return ;
	while (index < exec[0].nbr_cmds)
	{
		while (exec[index].args && exec[index].args[++i])
			exec[index].args[i] = rm_quote(exec[index].args[i]);
		index++;
	}
}
