/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:32:58 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/06 11:31:19 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* The parser handles 3 things:
	* 1. open quotes - output: invalid input
	* 2. skips unnecessary whitespaces
	* 3. splits every possible command into a matrix of tokens (cmdline[][])
*/

void split_cmds(char *line, int i, int space, t_token **lst_head)
{
	int test = i;
    int flag = 0;
    int start = i;
    while (line[i] && i < space)
    {
    	if (line[i] == '|' || line[i] == '>' || line[i] == '<')
        {
            if (i + 1 < space && line[i + 1] && line[i + 1] == line[i])
            {
				if (i > start)
                	add_node(lst_head, line, start, i);
                add_node(lst_head, line, i, i + 2);
                i += 2;
                flag = 0;
                start = i;
            }
            else
            {
				if (i > start)
                	add_node(lst_head, line, start, i);
                add_node(lst_head, line, i, i + 1);
                i += 1;
                flag = 0;
                start = i;

            }
        }
        else
        {
            flag++;
            i++;
        }
    }
    if (flag)
        add_node(lst_head, line, start, i);
    return ;
}

/* return value: nr of chars that later we'll copy
   example:
   cmdline = ola"adeus"ola
   we sent cmdline[4] as parameter, and the ft will stop at cmdline[10]
   ft_strchr will return 6 + 1, which is length of the str to tokenize*/

int strchr_wdlen(const char *s, int c)
{
	int		i;

	i = 1;
	while (s[i])
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return (i + 1);
		i++;
	}
	return (0);
}
char	*substr_new(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	cp_len;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		cp_len = 0;
	else if (start != 0)
		cp_len = len - start;
	else
		cp_len = len;
	new = (char *)malloc(cp_len + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < cp_len)
		new[i] = (char)s[start + i];
	new[i] = 0;
	return (new);
}

int add_node(t_token **lst_head, char *line, int i, int end)
{
    t_token *last;

    t_token *newnode = tokenize(line, i, end);
    if (!*lst_head)
    {
		newnode->before = '\0';
        *lst_head = newnode;
        return (end);
    }
    last = ft_tknlast(*lst_head);
    last->next = newnode;
    return (end);
}

void	parser(char *line, t_token **lst_head)
{
	int		i;
	int start;

	i = 0;
	if (count_quotes(line, i)) // if there are open quotes, returns 1
	{
		ft_printf("Error: invalid input\n");
		return ;
	}
	while (line[i])
	{
		if (line[i] == 39 || line[i] == 34)
			i += quote_handler(line, i, lst_head);
		else if (!ft_isspace(line[i]))
		{
			start = i;
			while (!ft_isspace(line[i]) && line[i])
			{
				if (line[i] == 39 || line[i] == 34)
				{
					if (i > start)
						split_cmds(line, start, i, lst_head);
					i += quote_handler(line, i, lst_head);
					start = i;
				}
				else
					i++;
			}
			if (i > start)
	        	split_cmds(line, start, i, lst_head);
		}
		while (ft_isspace(line[i]) && line[i])
            i++;
	}
	return ;
}
