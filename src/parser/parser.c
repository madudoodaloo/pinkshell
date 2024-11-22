/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:32:58 by msilva-c          #+#    #+#             */
/*   Updated: 2024/11/22 07:44:13 by msilva-c         ###   ########.fr       */
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
    printf("\n--- entered split_cmds ---\n");
	//while (test < space)
	//	printf("%c", line[test++]);
	//printf("$\n");
    //printf("\n--- starting to split ---\n");
    int flag = 0;
    int start = i;
    while (line[i] && i < space)
    {
    	if (line[i] == '|' || line[i] == '>' || line[i] == '<')
        {
            //printf("space is %d\ni is %d\nstart is %d\n", space, i, start);
			//printf("line[i] = %c\n", line[i]);
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

    ft_printf("--- adding node in lst_head ---\n");
    //ft_printf("i = %d, end = %d\n", i, end);
    //ft_printf("end - start(i) = %d\n", end - i);
	//char *substring = substr_new(line, i, end);
	//ft_printf("substring is: %s", substring);
    //ft_printf("$\nadded node\n");
	//free(substring);
	//return (end);
    t_token *newnode = tokenize(line, i, end);
    if (!*lst_head)
    {
		ft_printf("is in !*lst_head\n");
		newnode->before = '\0';
        *lst_head = newnode;
		printf("first node: %p\n", *lst_head);
		printf("current->next is: %p\n", (*lst_head)->next);
        return (end);
    }
    last = ft_tknlast(*lst_head);
	ft_printf("left ft_tknlast\n");
    last->next = newnode;
    return (end);
}

void	parser(char *line, t_token **lst_head)
{
	int		i;
	int start;

	i = 0;
	if (count_quotes(line, i))
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
