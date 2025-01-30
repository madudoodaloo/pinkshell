/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:32 by marianamest       #+#    #+#             */
/*   Updated: 2025/01/30 17:32:25 by marianamest      ###   ########.fr       */
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

// types for node struct

# include "../ft_libft/libft.h"
# include "builtins.h"
# include "expander.h"
# include "lexer.h"
# include "parser.h"
# include "signals.h"
# include "utils.h"

# define CMD 1
# define PIPE 2
# define REDIR 3
# define QUOTE 4
# define ENVVAR 5
# define STR 6
# define MAXLINE 1024

typedef struct s_token
{
	char			*content;
	int				type;
	char			before;
	int				after;
	struct s_token	*next;
}					t_token;

typedef struct s_msh
{
	char			*line;
	int				exit;
	int				ret;
	t_token			**lst_head;
	t_token			**ex_tokens;
	char			**env;
}					t_msh;

#endif
