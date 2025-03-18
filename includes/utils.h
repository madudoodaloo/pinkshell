/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:01:56 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 08:12:48 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes/minishell.h"

/* free_1.c */
void	free_token_list(t_token *tokens);
void	free_var(t_env *var);
void	free_env(t_env *env);
void	free_matrix(char **matrix);
void	free_pipex_list(t_exec *exec);

/* free_2.c */
void	free_and_exit(t_msh *msh);

/* heredoc_utils.c */
void	int_to_str(int num, char *str);

/* libft_utils1 */
void	ft_swap(char **a, char **b);
void	ft_swap_char(char *a, char *b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);

/* libft_utils2 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);

/* libft_utils3.c */
int		ft_isoperator(char *str, int i);
int		ft_isspace(char c);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isquote(char c);

/* libft_utils4.c */
int		ft_strcmp(const char *s1, const char *s2);
void	ft_put_str_fd(char *str, int fd);
int		ft_atoi(char *str);

/* malloc.c */
void	*ft_memset(void *s, int c, size_t n);
void	*safe_malloc(size_t size);

/* utils_builtins.c */
void	print_error(const char *message);
void	my_strcpy(char *dest, const char *src);
void	my_strcat(char *dest, const char *src);
int		ft_isalnum(int c);

/* utils_str.c */
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif
