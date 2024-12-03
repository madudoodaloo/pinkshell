/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/12/03 01:37:27 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *clearline(char *line, t_token **tokens)
{
    free(line);
    free_struct(tokens);
    return (NULL);
}

bool    handleline(t_msh *msh)
{
    if (msh->line)
        msh->line = clearline(msh->line, msh->ex_tokens);
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
        print_struct(msh->ex_tokens);
        if (!msh->ex_tokens)
            return (1);
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


int main(int ac, char **av, char **envp)
{
    (void)av;
    t_msh msh;

    init_all(&msh);
    //ft_printf("msh.head is: %p\n", msh.lst_head);
    msh.env = copy_matrix(envp);
    //ft_printf("msh.env[0] is: %s\n", msh.env[0]);
    if ((ac != 1) || !envp[0] || !envp)
        ft_printf("Error: Exiting.\n");
    signal(2, c_handler); //ctrl-C SIGINT
    signal(3, SIG_IGN); //ctrl-\ SIGQUIT
    while (msh.exit == 0)
    {
        msh.exit = handleline(&msh);
    }
    free_and_exit(&msh);
    return (msh.ret);
}
