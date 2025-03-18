/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:25:45 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 21:33:28 by msilva-c         ###   ########.fr       */
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

int	is_edge_expand(char *var_name)
{
	int	var_len;

	if (!var_name || !*var_name)
		return (0);
	else if (ft_strlen(var_name) != 2)
		return (0);
	else if (var_name[0] == '$')
	{
		if (var_name[1] == '?' || var_name[1] == '?')
			return (1);
	}
	else
		return (0);
}

char *edge_expand(char* var_name, t_msh *msh)
{
	char *var_value;

	var_value = ft_strdup("");
	if (ft_strlen(var_name) != 2)
		return (var_value);
	else if (var_name[1] == '?')
	{
		free(var_value);
		var_value = ft_itoa(msh->exit);
	}
	else if (var_name[1] == '$')
	{
		free(var_value);
		var_value = ft_itoa(getpid());
	}
	return (var_value);
}

char	*regular_expand(t_env *env, char *var_name)
{
	char	*var_value;

	var_value = ft_strdup("");
	if (!env || !var_name || !*var_name)
		return (var_value);

	while (env)
	{
		if (!ft_strcmp(var_name, env->var_name))
		{
			free(var_value);
			var_value = ft_strdup(env->var_value);
			break ;
		}
		env = env->next;
	}
	return (var_value);
}

void	update_content(t_token *token, char *expanded)
{
	char	*new_value;

	new = (char *)safe_malloc(sizeof(char) * (expanded_strlen(expanded) + 1))

}

void	expand_var(t_token *token, t_msh *msh)
{
	char	*var_name;
	char	*var_value;

	var_name = grep_var_name(token);
	if (is_edge_expand(var_name))
		var_value = edge_expand(var_name, msh);
	else
		var_value = regular_expand(msh->env, var_name);
	update_content(token, var_value);
	free(var_name);
	free(var_value);
}

void	expander(t_token *tokens)
{
	t_token	*temp;

	temp = tokens;
	while (temp)
	{
		ignore_dollar(temp->content);
		if (needs_expansion(temp))
			expand_var(temp, msh());
		else
		{
			put_dollar_back(temp->content);
			temp = temp->next;
		}
	}
}
