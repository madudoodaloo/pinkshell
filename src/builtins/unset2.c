/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:50:02 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/17 19:35:24 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Helper function to compare strings up to a delimiter (e.g., '=')
int	ft_strcmp_nochr(const char *s1, const char *s2, char delim)
{
	while (*s1 && *s2 && *s1 != delim && *s2 != delim && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if ((*s1 == delim || *s1 == '\0') && (*s2 == delim || *s2 == '\0'))
		return (0);
	return (*s1 - *s2);
}
