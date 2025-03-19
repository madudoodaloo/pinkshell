/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:19:12 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/19 06:26:56 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    clean_line(t_msh *msh)
{
    if (msh->line)
       free(msh->line);
}

void msh_loop(char **envp)
{
    init_all(envp);
    while (1)
    {
        msh()->line = readline("minishell$");
        if (!msh()->line)
        {
            ft_put_str_fd("exit\n", 2);
            break ;
        }
        if (msh()->line && *msh()->line)
        {
            add_history(msh()->line);
            if (parser())
                printf("parser done\n");
            //init_exec(msh())
            //execute(msh());
            else
                printf("parser failed\n");
            //msh()->exit = 2;
        }
        clean_line(msh());
    }
    free_and_exit();
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
