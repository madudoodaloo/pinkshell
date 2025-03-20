/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:04:58 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 16:17:36 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"


/* prep_redir.c */
int     prep_in_redir(char **in_redirs, t_exec *exec, int k);
int     doc_loop(char **in_redirs, t_exec *exec, int k);
int     open_infile_loop(char **in_redirs, t_exec *exec, int k);
int     is_final_heredoc(char **in_redirs, t_exec *exec, int k);
bool    check_and_open_file(char *file_name);

/* run_doc.c */
int     run_doc(char *delimiter, t_exec *exec, int k);
void    read_into_heredoc(char *delimiter, t_exec *exec, int k);
void    control_d_handle(t_exec *exec, int k, char *str);
void    write_to_pipe(char *str, t_exec *exec);

/* waitpid.c */
void    ft_waitpid(int pid);
void    write_to_pipe(char *str, t_exec *exec);
void    close_pipe(int *fd);
void    safe_close(int fd);

#endif
