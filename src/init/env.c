/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:27:31 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/08 02:58:05 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	n;
	unsigned int	i;

	if (!s)
		return (NULL);
	n = ft_strlen((char *)s);
	if (start >= n || len == 0)
		return (ft_calloc(1, 1));
	if (len > n - start)
		len = n - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

t_env	*add_var(char *str)
{
	t_env *new;
	int i;

	i = 0;
	new = (t_env *)safe_malloc(sizeof(t_env));
	new->var = ft_strdup(str);
	while (str[i] && str[i] != '=')
		i++;
	new->var_name = ft_substr(str, 0, i);
	if ()
}

t_env *copy_env(void)
{

}

t_env *empty_env(void)
{

}

int	check_env(char **envp)
{
	int i = 0;
	if (!envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

t_env	*get_env(char **envp)
{
	int i;
	t_env	*new;
	t_env	*temp;

	i = -1;
	if (check_env(envp) == 0)
		new = empty_env();
	else
	{
		while (envp[++i])
		{
			temp = add_var(envp[i]);
			if (i > 0)
				add_var_back(new, temp);
		}
	}
	return (new);
}
