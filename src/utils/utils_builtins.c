/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:18:43 by marianamest       #+#    #+#             */
/*   Updated: 2024/12/05 12:30:22 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_struct(t_token **lst_head)
{
	t_token *current;
	t_token *counter;


	current = *lst_head;
	counter = *lst_head;
	int i = 0;
	while (counter)
	{
		i++;
		counter = counter->next;
	}
	printf("has %d nodes\n", i);
	while (current)
	{
			printf("node: %p\n", current);
			printf("type: %d\n", current->type);
			if (current->content != NULL)
				printf("content: %s$\n", current->content);
			else
				printf("content: (null)$\n");
			current = current->next;
	}
}

void	print_error(const char *message)
{
	printf("Error: %s\n", strerror(errno));
}

void	my_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	my_strcat(char *dest, const char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
}
