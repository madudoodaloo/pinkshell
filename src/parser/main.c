/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:01:56 by skioridi          #+#    #+#             */
/*   Updated: 2024/11/22 03:12:49 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    free_struct(t_token **head)
{
    t_token *temp;
    temp = head->next;
    while (temp->next)
    {
        if (temp)
            free_token(temp);
        temp
    }
}

char *clearline(char *line, t_token **head)
{
    free(line);
    free_struct(head);
    return (NULL);
}

bool    handleline(t_msh *msh)
{
    if (msh->line)
        msh->line = clearline(msh->line, msh->lst_head);
    msh->line = readline("minishell$");
    if (msh->line && *msh->line)
        add_history(msh->line);
    if (msh->line && !ft_strncmp(msh->line, "exit", ft_strlen(msh->line)))
        return (1);
    else if (msh->line)
    {
        printf("\nfull cmdline: %s\n\n", msh->line);
        final_lexer(msh->line, msh->lst_head);
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
    msh.env = copy_matrix(envp);
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
