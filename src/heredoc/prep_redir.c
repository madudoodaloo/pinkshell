/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:29:52 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/19 22:06:46 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int prep_in_redir(t_exec *exec)
{
    int i;

    i = 0;
    while(i < exec[i].nr_cmds) // value might be somewhere else
    {
        if(exec[i].redir_in != NULL)
        {
            //is_final_heredoc
            doc_loop(exec[i].redir_in, exec, i);
        }
        i++;
    }
    i = 0;
    while(i < exec[i].nr_cmds)
    {
        open_infile_loop();
    }
}

// rever : is_final_heredoc -> checks if heredoc is last redir and updates is_heredoc bool

int doc_loop (char **in_redirs, t_exec *exec, int k) // recebe da prep_in_redir e i de index de onde estou no arr do exec e k para char **
{
    int i = 0;
    while(in_redirs[i] != NULL)
    {
        if(!ft_strncmp(in_redirs[i], "app:", 4)) // append flag
        {
            safe_close(exec[k].heredoc_pipefd[0]); // qual fd
           if(run_doc(in_redirs[i] + 4, exec, k) < 0) 
            return (-1);
        }
        i++;
    }
    if(!is_final_heredoc())
        close(exec[k].heredoc_pipefd[0]);        
}

int open_infile_loop(char **in_redirs, t_exec *exec, int k)
{
    int i;
    int fd;
    
    i = 0;
    while(in_redirs[i] != NULL)
    {
        if (ft_strncmp(in_redirs[i], "app:", 4) != 0)
        if(/*return da nova func < 0*/)
            //fd = open(in_redirs[i] + 4, O_RDONLY);
            exec[k]->command_invalid = true;
    }
    if(exec[k].is_heredoc)
    safe_close(exec->in_fd);
}

// nome de funncao novo
// if(fd = open(in_redirs[i] + 4, O_RDONLY);)
// verificar se nome esta vazio 
// verificar o retorno do open


