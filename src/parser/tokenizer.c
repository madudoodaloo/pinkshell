/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:09:20 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/15 17:12:38 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//rever
int	get_token_type(char *str)
{
	if (!str)
		return (-1);
	else if (str[0] == '>' && str[1] == '\0')
		return (RED_OUT);
	else if (str[0] == '>' && str[1] == '>' && str[2] == '\0')
		return (RED_APP);
	else if (str[0] == '<' && str[1] == '\0')
		return (RED_IN);
	else if (str[0] == '<' && str[1] == '<' && str[2] == '\0')
		return (HERE_DOC);
	else if (str[0] == '|' && str[1] == '\0')
		return (PIPE);
	else
		return (WORD);
}

t_token	*init_token(char *str)
{
	t_token	*new_t;
	int		str_len;

	new_t = (t_token *)safe_malloc(sizeof(t_token) + 1);
	if (!new_t)
		return (NULL);
	str_len = ft_strlen(str);
	new_t->token = safe_malloc(str_len + 1);
	if (!new_t->token)
	{
		free (new_t);
		return (NULL);
	}
	ft_strlcpy(new_t->token, str, str_len + 1);
	if (new_t->token)
		new_t->token_type = get_token_type(str);
	else
		new_t->token_type = -1;
	new_t->index = -1;
	new_t->next = NULL;
	new_t->previous = NULL;
	return (new_t);
}

void	token_add_back(t_token *start, t_token *add)
{
	t_token	*step;

	step = start;
	while (step->next != NULL)
		step = step->next;
	add->previous = step;
	step->next = add;
}

int	count_strs(char **words)
{
	int	i;

	i = 0;
	if (!words)
		return (0);
	while (words[i] != NULL)
		i++;
	return (i);
}

t_token	*tokenizer(char **words)
{
	t_token	*start;
	t_token	*add;
	int		i;

	if (count_strs(words) == 0)
		return (NULL);
	start = init_token(words[0]);
	i = 1;
	while (words[i] != NULL)
	{
		add = init_token(words[i]);
		token_add_back(start, add);
		i++;
	}
	ft_free_matrix(words);
	return (start);
}
