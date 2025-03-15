/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2025/03/15 16:33:03 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *clearline(t_msh *msh)
{

}

bool    handleline(t_msh *msh)
{
    if (msh->line)
        msh->line = clearline(msh);
    msh->line = readline("minishell$");
    if (msh->line && *msh->line)
        add_history(msh->line);
    if (msh->line && !ft_strncmp(msh->line, "exit", ft_strlen(msh->line)))
        return (1);
    else if (msh->line)
    {
        parser(msh->line, msh->lst_head);
        //print_struct(msh->lst_head);
        lexer(msh->ex_tokens, msh->lst_head);
        if (!msh->ex_tokens)
            return (1);
        print_struct(msh->ex_tokens);
        expander(*(msh->ex_tokens), msh->env);
    }
    else
        return (1);
    return (0);
}

void    c_handler()
{
    ft_printf("\n"); // Move to a new line
    rl_on_new_line(); // Regenerate the prompt on a newline
    rl_replace_line("", 0); // Clear the previous text
    rl_redisplay();
    return ;
}
void msh_loop(char **envp)
{
    init_all(envp);
    signal(2, c_handler); //ctrl-C SIGINT
    signal(3, SIG_IGN); //ctrl-\ SIGQUIT
    while (msh()->exit == 0)
    {
        msh()->exit = handleline(&msh);
    }
    free_and_exit(msh());
    return (msh()->ret);
}

int main(int ac, char **av, char **envp)
{
    (void)av;
    t_msh msh;

    if (ac == 1)
    {
        //inserir aqui a init dos sinais
        msh_loop(envp);
    }
    else
        printf("Cmdline to launch: ./minishell\n");
    return (0);
}
