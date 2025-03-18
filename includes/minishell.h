/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:32 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/17 20:31:11 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

volatile sig_atomic_t	g_signal = 0;

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/* ../includes headers */
# include "builtins.h"
# include "expander.h"
# include "heredoc.h"
# include "lexer.h"
# include "parser.h"
# include "signals.h"
# include "utils.h"
# include "executor.h"

# define CMD 1
# define PIPE 2
# define R_OUT 3
# define R_APP 4
# define R_IN 5
# define HERE_DOC 6
# define MAXLINE 1024
# define MAXPATH 4096

typedef struct s_env
{
	char				*var;
	char				*var_name;
	char				*var_value;
	int valid; // inicializar para false
	struct s_env		*next;
}						t_env;

typedef struct s_token
{
	char		*content;
	int 		type;
	int			index;
	struct s_token	*next;
	struct s_token	*prev;
}			t_token;

typedef struct s_exec
{
	int				pid;
	int				pipe[2];
	int				has_doc;
	int				doc_pipe[2];
	int				out_fd;
	int				in_fd;
	bool			last_child;
	bool			bad_command;
	char			*path;
	char			**red_out;
	char			**red_in;
	char			**cmd;
	struct s_pipex	*next;
	struct s_pipex	*previous;
}			t_exec;

typedef struct s_msh
{
	char				*line;
	char				*home;
	char				*pwd;
	t_env				*env;
	t_token				*tokens;
	t_exec				*exec;
	int					exit;
	int					signaled;
	int					ret;
}						t_msh;

typedef enum e_temp_op
{
	TEMP_DOLLAR = -1,
	TEMP_PIPE = -2,
	TEMP_IN = -3,
	TEMP_OUT = -4,
}		t_temp_op;

t_msh	*msh(void);

#endif
