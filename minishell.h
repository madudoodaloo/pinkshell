/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:32 by marianamest       #+#    #+#             */
/*   Updated: 2024/11/08 17:37:56 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/* error handling */
void	print_error(const char *message);

/* CD */
char	*find_env_value(char **env, const char *var);
int		get_current_directory(char *buffer, int size);
void	update_pwd_vars(char **env, const char *old_pwd, const char *new_pwd);
void	change_directory(char **env, const char *path);
void	cd_command(char **env, char **args);

/* env */
char	*create_env_entry(const char *key, const char *value);
char	**allocate_and_init_env_array(char **envp);
int     process_env_variable(char *env_var, char **env, int i);
char	**init_env_array(char **envp);
int		find_env_key_index(char **env, const char *key);
char	**update_env_var(char *arg, char **env, int idx);
char	**expand_env(char **env, char *new_entry);
void	set_or_add_env_value(char ***env, const char *key, const char *value);

/* helper functions */
void	my_strcpy(char *dest, const char *src);
void	my_strcat(char *dest, const char *src);

#endif
