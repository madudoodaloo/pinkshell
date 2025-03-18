/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:19:12 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/18 01:14:45 by msilva-c         ###   ########.fr       */
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
        m->line = readline("minishell$");
        if (!m->line)
        {
            ft_put_str_fd("exit\n", 2);
            break ;
        }
        if (m->line && *m->line)
        {
            //rever se o heredoc n precisa dum counter
            add_history(m->line);
            if (parser(m))
                printf("great success parsed\n");
            else
                printf("great success parsed\n");
            /*
            if (parser(m) && init_exec(m))
            execute(m);
            else
            msh()->exit = 2;
            */
        }
        clean_line();
    }
    free_and_exit(m);
}

int main(int ac, char **av, char **envp)
{
    (void)av;

    if (ac == 1)
    {
        //setup_signals();
        msh_loop(envp);
    }
    else
        printf("Cmdline to launch: ./minishell\n");
    return (0);
}
