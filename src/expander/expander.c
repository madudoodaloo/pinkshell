/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:25:45 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 19:10:44 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	needs_expand(t_token *t)
{
	int	i;

	i = 0;
	if (!t || !t->token)
		return (false);
	if (ft_strlen(t->token) == 1 && t->token[0] == '$')
		return (false);
	while (t->token[i] != '\0')
	{
		if (t->previous && t->previous->token_type == HERE_DOC)
			return (false);
		if (t->token[i] == '$' && !in_squote(t->token, i))
			return (true);
		i++;
	}
	return (false);
}

void	expander(t_token *tokens)
{
	t_token	*temp;

	temp = tokens;
	while (temp)
	{
		ignore_dollar(temp->content);
		if (needs_expand(temp))
			do_expand(temp);
		else
		{
			put_dollar_back(temp->content);
			temp = temp->next;
		}
	}
}

//rever tudo
void	do_expand(t_token *t)
{
	char	*var_name;
	char	*var_value;

	var_name = get_var_name(t);
	if (is_special_expand(var_name))
		var_value = get_special_var(var_name);
	else
		var_value = get_var_value(msh()->env, var_name);
	expand_var(t, var_value);
	free(var_name);
	free(var_value);
}

static void	init_index(t_index *i)
{
	i->new_i = 0;
	i->t_i = 0;
	i->var_i = 0;
}


void	expand_var(t_token *t, char *var)
{
	char	*new;
	t_index	i;

	init_index(&i);
	new = safe_malloc(expanded_len(t, var) + 1);
	while (t->content[i.t_i] != '$')
		new[i.new_i++] = t->content[i.t_i++];
	while (var[i.var_i] != '\0')
		new[i.new_i++] = var[i.var_i++];
	if (t->content[i.t_i + 1] == '?' || t->content[i.t_i + 1] == '$')
		i.t_i += 2;
	else
		i.t_i += var_name_len(t->content, i.t_i + 1) + 1;
	while (t->content[i.t_i] != '\0')
		new[i.new_i++] = t->content[i.t_i++];
	new[i.new_i] = '\0';
	free(t->content);
	t->content = new;
}
