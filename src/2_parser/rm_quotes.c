/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 04:54:10 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/20 07:37:57 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	skip_quotes(char *str, int i)
{
	int	len;

	len = i;
	if (str[len] == 34)
	{
		len++;
		while (str[len] && str[len] != 34)
			len++;
		return (len + 1 - i);
	}
	else if (str[len] == 39)
	{
		len++;
		while (str[len] != 39 && str[len])
			len++;
		return (len - i + 1);
	}
	else
		return (-1);
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

static void	copy_quote(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

char *rm_quote(char*str, int i)
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
		rm_diff(str, i + 1, new, i_new);
	free(str);
	return (new);

}
void	rm_quotes_exec(t_exec	*exec)
{
	int		i;
	int index;

	i = -1;
	index = 0;
	while (index < exec[0].nbr_cmds)
	{
		while (exec[index].redir_in && exec[index].redir_in[++i])
			exec[index].redir_in[i] = rm_quote(exec[index].redir_in, i);
		i = -1;
		while (exec[index].redir_out && exec[index].redir_out[++i])
			exec[index].redir_out[i] = rm_quote(exec[index].redir_out, i);
		i = -1;
		while (exec[index].args && exec[index].args[++i])
			exec[index].args[i] = rm_quote(exec[index].args, i);
		index++;
	}
}
