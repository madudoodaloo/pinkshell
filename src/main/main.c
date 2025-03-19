/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:19:12 by msilva-c          #+#    #+#             */
/*   Updated: 2025/03/19 09:24:17 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



static void print_msh(t_msh *msh)
{
    t_token *token;

    if (!msh)
    {
        printf("msh is NULL\n");
        return;
    }

    printf("msh->line: %s\n", msh->line ? msh->line : "(NULL)");
    printf("msh->home: %s\n", msh->home ? msh->home : "(NULL)");
    printf("msh->pwd: %s\n", msh->pwd ? msh->pwd : "(NULL)");
    printf("msh->env: %p\n", (void *)msh->env);
    printf("msh->exec: %p\n", (void *)msh->exec);
    printf("msh->data: %p\n", (void *)msh->data);
    printf("msh->exit: %d\n", msh->exit);

    printf("Tokens:\n");
    token = msh->tokens;
    if (!token)
        printf("  (NULL)\n");
    while (token)
    {
        printf("  Token content: %s\n", token->content ? token->content : "(NULL)");
        printf("  Token type: %d\n", token->type);
        printf("  Token index: %d\n", token->index);
        printf("  Token next: %p\n", (void *)token->next);
        printf("  Token prev: %p\n", (void *)token->prev);
        token = token->next;
    }
}

void    clean_cmdline(void)
{
    t_msh *m;

    m = msh();
    if (!m)
        return ;
    if (m->line)
        free(m->line);
    if (m->tokens)
    {
        free_tokens(m->tokens);
        m->tokens = NULL;
    }
    if (m->exec)
    {
        free_exec(m->exec);
        m->exec = NULL;
    }
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
            {
                print_msh(msh());
                if (init_exec())
                {
                    printf("has entered exec\n");
                    start_execution();
                }
                else
                    printf("init_exec() = %d\n", init_exec());
            }
            else
                printf("parser() = %d\n", parser());
            //msh()->exit = 2;
        }
        clean_cmdline();
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
