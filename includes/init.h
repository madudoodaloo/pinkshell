/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:59:04 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/08 16:09:24 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../includes/minishell.h"

/* env.c */
t_env	*create_var(char *var);
t_env *copy_env(void);
t_env *empty_env(void);
int	check_env(char **envp);
t_env	*get_env(char **envp);


/* init.c */
t_msh	*msh(void);
t_msh    *init_all(t_msh *msh);

#endif
