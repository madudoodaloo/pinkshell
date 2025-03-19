/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:32 by marianamest       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/19 01:54:13 by marianamest      ###   ########.fr       */
=======
/*   Updated: 2025/03/19 01:32:21 by msilva-c         ###   ########.fr       */
>>>>>>> e5ed60d855f8fc0150f288f3740c8161e5d6958f
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

# define CMD 1
# define PIPE 2
# define R_OUT 3
# define R_APP 4
# define R_IN 5
# define HERE_DOC 6
# define MAXLINE 1024
# define MAXPATH 4096

sig_atomic_t	g_signal = 0;

// void *struct - rever!!!  Placeholder for resources to free
// rever se ainda vai ser preciso dps da ft_dup_env - Environment variables
typedef struct s_data
{
	bool				is_heredoc;
	void				*strut;
	char				**envp;
	struct s_msh		*msh;
}						t_data;

typedef struct s_env
{
	char				*var; // PATH=usr/folder
	char				*var_name; // PATH
	char				*var_value; // usr/folder/
	int					valid;
	struct s_env		*next;
}						t_env;

typedef struct s_token
{
	char				*content;
	int					type;
	int					index;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_exec
{
	int					pid;
	int					pipe[2];
	int					has_doc;
	int					doc_pipe[2];
	int					out_fd;
	int					in_fd;
	bool				last_child;
	bool				bad_command;
	char				*path;
	char				**red_out;
	char				**red_in;
	char				**cmd;
	struct s_pipex		*next;
	struct s_pipex		*previous;
}						t_exec;

//rever: criar uma ft que transforma linked list em char **
typedef struct s_msh
{
	char				*line;
	char				*home;
	char				*pwd;
	t_env				*env;
	t_token				*tokens;
	t_exec				*exec;
	t_data				*data;
	int					exit;
}						t_msh;

typedef enum e_temp_op
{
	TEMP_DOLLAR = -1,
	TEMP_PIPE = -2,
	TEMP_IN = -3,
	TEMP_OUT = -4,
}						t_temp_op;

t_msh					*msh(void);

/* ../includes/*.h */
# include "builtins.h"
# include "executor.h"
# include "expander.h"
# include "heredoc.h"
# include "parser.h"
# include "signs.h"
# include "utils.h"

#endif
