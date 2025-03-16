/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:59:01 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/16 22:04:18 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int count_words(char *str)
{

}

int parser_wdlen(char *str, int i)
{
	int len;

	len = 0;
	while (str[i + len])
	{
		if (!ft_isspace(str[i + len]))
			len++;
		else if (ft_isspace(str[i + len]) && check_quotes(str, i + len)) //test: see if in_quotes is working
			len++;
		else
			return (len);
	}
	return (len);
}

char	**split_spaces(char *line)
{
	char **matrix;
	int wc;
	int i;
	int j;

	i = 0;
	j = 0;
	wc = count_words(line);
	matrix = (char **)safe_malloc(sizeof(char *) * (wc + 1));
	if (!matrix)
		return (NULL);
	while (j < wc)
	{
		while (ft_isspace(line[i]))
			i++;
		matrix[j] = ft_substr(line, i, parser_wdlen(line, i)); // ver se está a guardar bem
		if (!matrix[j++])
			return (matrix);
		i += parser_wdlen(line, i);
	}
	matrix[j] = NULL;
	return (matrix);
}


int tokenizer(t_msh *msh)
{
	char **temp;

	temp = split_spaces(msh->line);
	if (!temp)
		return (-1);
	if (!split_spaces(msh->tokens))
		return (-1);
}
