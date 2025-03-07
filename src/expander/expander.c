/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:40:30 by msilva-c          #+#    #+#             */
/*   Updated: 2025/02/25 00:18:17 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


/* returns, if found and if it's suposed to be expanded, the [i] where the $ was found
 * it should not expand if the $ is inside simples quotes, despite possible ""
 */
int check_quotes(char *str, int i)
{
	while (str[i])
	{
		if (ft_strchr(str, 39) < ft_strchr(str, 34) && str[i] > ft_strchr(str, 39) && str[i] < ft_strchr(ft_strchr(++str, 39), 39))
			return (0);
		return (i);
	}
}

char *get_var_value(char *var_name, char **env)
{
	int i = 0;
	int j = 0;
	char *var_value = NULL;

	while (env[i])
	{
		if (ft_strncmp(env[i], var_name, ft_strlen(var_name)) == 0)
		{
			j = ft_strlen(var_name);
			if (env[i][j] == '=')
			{
				var_value = ft_strdup(env[i] + j + 1);
				break ;
			}
		}
		i++;
	}
	free(var_name);
	return (var_value);
}


char *get_var_name(char *line, int i)
{
	int j = i;
	char *var_name = NULL;

	while (line[j] && (ft_isalnum(line[j]) || line[j] == '_'))
		j++;
	var_name = ft_substr(line, i, j - i);
	return (var_name);
}

int replace_dollar(char *line, int i, char **env)
{
	int n = 0;
	int j = 0;
	char *var_name = NULL;
	char *var_value = NULL;

	var_name = get_var_name(line, i);
	if (var_name)
		var_value = get_var_value(var_name, env);
	if (var_value)
	{
		printf("var_name: %s\n", var_name);
		printf("var_value: %s\n", var_value);

	}
	{
		n = ft_strlen(var_name);
		while (var_value[j])
			j++;
		line = ft_strjoin(ft_strjoin(ft_substr(line, 0, i), var_value), ft_substr(line, i + n, ft_strlen(line) - i - n));
		free(var_value);
	}


}

void	expander(t_token *tokens, char **env)
{
	t_token	*node;
	char *line;
	char *new;
	int i;

	node = tokens;
	new = NULL;
	line = NULL;
	int flag = 0;
	//print_matrix(env);
	//return ;
	while (node)
	{
		i = 0;
		line = node->content;
		while (line[i] && node->type == 1)
		{
			if (line[i] == 39 && flag == 0)
				flag = 1;
			else if (line[i] == 39 && flag == 1)
				flag = 0;
			else if (line[i] == '$' && flag == 0)
				new = replace_dollar(line, i, env);
			i++;
		}
		free(node->content);
		node->content = new;
		node = node->next;
	}
}
