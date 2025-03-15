/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:01:56 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/15 19:43:22 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes/minishell.h"

/* free.c */
void    free_struct(t_token **head);
void   free_and_exit(t_msh *msh);
void	ft_free_matrix(char **matrix);
void	free_all(void *strut);

/* testers */
void	print_struct(t_token **lst_head);

/* error handling */
void	print_error(const char *message);

/* helper functions */
void	my_strcpy(char *dest, const char *src);
void	my_strcat(char *dest, const char *src);
#endif
