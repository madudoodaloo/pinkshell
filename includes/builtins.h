/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:01:00 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/15 20:16:37 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../includes/minishell.h"

/* cd */
char	*find_env_value(char **env, const char *var);
int		get_current_directory(char *buffer, int size);
void	change_directory(char **env, const char *path);
void	cd_command(char **env, char **args);

/* env */
char	*create_env_entry(const char *key, const char *value);
char	**allocate_and_init_env_array(char **envp);
int		process_env_variable(char *env_var, char **env, int i);
char	**init_env_array(char **envp);
int		find_env_key_index(char **env, const char *key);
char	**update_env_var(char *arg, char **env, int idx);
char	**expand_env(char **env, char *new_entry);
void	set_or_add_env_value(char ***env, const char *key, const char *value);

/* pwd */
void	my_pwd(int fd);

/* echo */
int		is_flag_n(char *str);
void	print_args(char **args, int start_index);
void	run_echo(char **args);

/* exit */
int		exit_format_error(char *cmd);
int		normalize_exit_code(int code);
void	exit_error(char *arg);
void	exec_exit(char **args);


#endif
