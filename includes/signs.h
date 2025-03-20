/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:26:02 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/20 04:22:44 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNS_H
# define SIGNS_H

# include "../includes/minishell.h"

/* signals.c */
void    init_signals(void);
void	sigint_handler(int sig);
void    signals_parent(void);
void    signals_ignore(void);
void    signals_default(void);

#endif
