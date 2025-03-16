/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:01:56 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/15 20:30:42 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes/minishell.h"

/* env.c */
char **copy_matrix(char **src);

/* str.c */
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

/* malloc.c */
void	*ft_memset(void *s, int c, size_t n);
void *safe_malloc(size_t size);

/* free.c */
void    free_struct(t_token **head);
void   free_and_exit(t_msh *msh);
void	ft_free_matrix(char **matrix);

/* testers */
void	print_struct(t_token **lst_head);

/* error handling */
void	print_error(const char *message);

/* helper functions */
void	my_strcpy(char *dest, const char *src);
void	my_strcat(char *dest, const char *src);
#endif
