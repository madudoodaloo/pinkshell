/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:32 by marianamest       #+#    #+#             */
/*   Updated: 2024/11/22 07:05:54 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../ft_libft/libft.h"

# define MAXLINE 1024

typedef struct s_token
{
	char		*content;
	int 		type;
	char		before;
	char		after;
	struct s_token	*next;
}			t_token;

typedef struct s_msh
{
	char		*line;
	int		exit;
	int		ret;
	t_token **lst_head;
	t_token	**ex_tokens;
	char **env;
}			t_msh;

// types for node struct
#define CMD 1
#define PIPE 2
#define REDIR 3
#define QUOTE 4
#define ENVVAR 5
#define STR 6


# include "parser.h"
# include "builtins.h"
# include "utils.h"

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
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

#endif
