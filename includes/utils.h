/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:01:56 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 00:58:55 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

/* env.c */
char	**copy_matrix(char **src);

/* free.c */
void free_token_list(t_token *tokens);
void free_var(t_env *var);
void free_env(t_env *env);
void free_matrix(char **matrix);
void free_pipex_list(t_exec *exec);
void free_and_exit(t_msh *msh);

/* str.c */
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

/* malloc.c */
void	*ft_memset(void *s, int c, size_t n);
void	*safe_malloc(size_t size);

/* free.c */
void	free_struct(t_token **head);
void	free_and_exit(t_msh *msh);
void	ft_free_matrix(char **matrix);

/* testers */
void	print_struct(t_token **lst_head);

/* error handling */
void	print_error(const char *message);

/* libft_2.c */
int ft_strcmp(const char *s1, const char *s2);

/* libft.c */
int	ft_isoperator(char *str, int i);
int	ft_isspace(char c);
int	ft_isalpha(char c);
int	ft_isdigit(char c);
int	ft_isquote(char c);

int		ft_isalnum(int c);

/* libft_utils1 */
void	ft_swap(char **a, char **b);
void	ft_swap_char(char *a, char *b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);

/* libft_utils2 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
#endif
