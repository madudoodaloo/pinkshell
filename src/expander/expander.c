/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:25:45 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 20:36:34 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	needs_expansion(t_token *token)
{
	int	i;

	if (!token || !token->content)
		return (0);
	if (token->content[0] == '$' && !token->content[1])
		return (0);
	i = -1;
	while (token->content[++i])
	{
		if (token->prev && token->prev->type == HERE_DOC)
			return (0);
		if (token->content[i] == '$' && !in_singles(token->content, i))
			return (1);
		i++;
	}
	return (0);
}

int	var_name_len(char *str, int i)
{
	int len;

	len = 0;
	if (!ft_isalpha(str[i]) && str[i] != 95)
		return (0);
	else if (ft_isdigit(str[i]))
		return (1);
	while (str[i + len] && str[i + len] != '$' && str[i + len] != TEMP_DOLLAR && !ft_isquote(str[i + len]))
	{
		if (ft_isdigit(str[i + len]) || ft_isalpha(str[i + len]) || str[i + len] == '_')
			len++;
		else
			return (len);
	}
}

// rever preciso de ter o $$ feito????
char *grep_var_name(t_token *token)
{
	char *var_name;
	int i;

	i = 0;
	while (token->content[i] != '$')
		i++;
	i++;
	if (token->content[i] == '$')
		var_name = ft_strdup("$$");
	else if (token->content[i] == '?')
		var_name = ft_strdup("$?");
	else
		var_name = ft_substr(token->content, i, var_name_len(token->content, i));
	return (var_name);
}

int	is_special_expand(char *var_name)
{
	int	var_len;

	if (!*var_name)
		return (0);
	var_len = ft_strlen(var_name);
	if (!ft_strncmp(var_name, "$", var_len))
		return (1);
	else if (!ft_strncmp(var_name, "?", var_len))
		return (1);
	else
		return (0);
}

char *edge_expand(char* var_name, t_msh *msh)
{
	char *var_value;

	if (ft_strlen(var_name) != 2)
		return NULL;
	else if (var_name[1] == '?')
		var_value = ft_itoa(msh->exit);
	else if (var_name[1] == '$')
		var_value = ft_itoa(getpid());
	else
		var_value = ft_strdup("");
	return (var_value);
}

void	expand_var(t_token *token)
{
	char	*var_name;
	char	*var_value;

	var_name = grep_var_name(token);
	if (is_edge_expansion(var_name))
		var_value = edge_expand(var_name);
	else
		var_value = regular_expand(msh()->env, var_name);
	rm_dollar(token, var_value);
	free(var_name);
	free(var_value);
}

static void	init_index(t_index *i)
{
	i->new_i = 0;
	i->t_i = 0;
	i->var_i = 0;
}


void	sub_dollar(t_token *t, char *var)
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

void	expander(t_token *tokens)
{
	t_token	*temp;

	temp = tokens;
	while (temp)
	{
		ignore_dollar(temp->content);
		if (needs_expansion(temp))
			expand_var(temp);
		else
		{
			put_dollar_back(temp->content);
			temp = temp->next;
		}
	}
}
