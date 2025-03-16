/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:19:12 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/16 20:00:59 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

void msh_loop(char **envp)
{
    t_msh *m;

    init_all(envp);
    m = msh();
    while (m->exit == 0)
    {
        if (m->line)
            m->line = clearline(m);
        m->line = readline("minishell$");
        if (m->line && *m->line)
        {
            add_history(m->line);
            if (parser(m))
                execute(m);
            else
                m->exit = 2;
        }
        clean_cmdline();
    }
    free_and_exit(m);
}

int main(int ac, char **av, char **envp)
{
    (void)av;

    if (ac == 1)
    {
        setup_signals();
        msh_loop(envp);
    }
    else
        printf("Cmdline to launch: ./minishell\n");
    return (0);
}
