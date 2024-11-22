/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:18:43 by marianamest       #+#    #+#             */
/*   Updated: 2024/11/22 11:47:40 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_struct(t_token **lst_head)
{
	t_token *current;

	current = *lst_head;
	int i = 0;
	while (current)
	{
		i++;
		printf("node %d is: %p\n", i, current);
		printf("content: %s$\n", current->content);
		printf("type: %d\n", current->type);
		if (current->before != '\0')
			printf("before: %c$\n", current->before);
		else
			printf("before: %d$\n", current->before);
		printf("after: %c$\n", current->after);
		printf("next: %p\n", current->next);
		printf("----------\n");

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
