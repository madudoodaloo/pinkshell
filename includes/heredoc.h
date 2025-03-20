/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:04:58 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 14:05:58 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"

// /* heredoc 1 */
// const char	*extract_var_name(const char *start, char *var_name);
// char		*expand_variables(const char *input);
// char		*get_delimiter(char *str, int i);
// int			heredoc_parser(char *str);
// void		read_until_delimiter(int fd, char *delimiter);

// /* heredoc 2 */
// void		signal_handler_set_temp_filename(char *filename);
// char		*generate_temp_filename(void);
// int			create_temp_file(char *temp_filename);
// void		redirect_temp_file_to_stdin(char *temp_filename);
// void		handle_heredoc(t_data *data, char *delimiter);

/* heredoc_utils */
void	int_to_str(int num, char *str);

/* new and improved -> run_doc.*/
int		run_doc(char *delimiter, t_exec *exec, int k);
void	close_pipe(int *fd);
void	safe_close(int fd);
void	read_into_heredoc(char *delimiter, t_exec *exec, int k);
void	control_d_handle(t_exec *exec, int k, char *str);

/* waitpid */
void	ft_waitpid(int pid);
void	write_to_pipe(char *str, t_exec *exec);

/* prep redir */
int		doc_loop(char **in_redirs, t_exec *exec, int k);
int		prep_in_redir(char **in_redirs, t_exec *exec, int k);
int		open_infile_loop(char **in_redirs, t_exec *exec, int k);
int		is_final_heredoc(char **in_redirs, t_exec *exec, int k);
bool	check_and_open_file(char *file_name);

#endif
