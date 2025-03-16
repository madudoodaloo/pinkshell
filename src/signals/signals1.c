/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:26:33 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/16 17:44:57 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_signal = 0;

t_data	*msdata(void)
{
	static t_data	data;

	return (&data);
}
void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		if (msdata()->is_heredoc)// se estiver dentro do modo heredoc vai sair
		{
			msdata()->is_heredoc = 0; // reset da flag para 0 para indicar que o heredoc ja nao esta ativo
			g_signal = SIGINT;
			close(STDIN_FILENO); // fecha o stdin fd
			return ;
		}
		rl_on_new_line(); // se não estiver em heredoc da so reset do prompt
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal = SIGINT;
	}
}

void	handle_signals_and_cleanup(t_data *data)
{
	if (g_signal == SIGINT) // se for SIGINT
	{
		g_signal = 0; // da clear do estado do sinal
		if (data->is_heredoc)
		{
			free_all(data->strut); // se estiver no heredoc limpa a memoria que estava alocada
			exit(130); // codigo do SIGINT
		}
		else
			write(1, "\n", 1); // se nao estiver em heredoc mete so na linha nova do prompt
	}
	else if (g_signal == SIGQUIT)
	{
		g_signal = 0;
		write(STDERR_FILENO, "Quit (core dumped)\n", 20);
	}
}

void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler; // da set do signal handler do SIGNIT
	sa.sa_flags = SA_RESTART; // faz com que system calls interrompidas pelo SIGINT dão restart automaticamente
	sigemptyset(&sa.sa_mask); // inicializa a signal mask para excluir quaisquer outros sinais durante a execução do signal handler
	sigaction(SIGINT, &sa, NULL); // aplica a configuração ao SIGINT
	sa.sa_handler = SIG_IGN; // Ignora SIGQUIT
	sigaction(SIGQUIT, &sa, NULL); // apllica a configuração ao SIGQUIT
	rl_clear_signals(); // da reset ao signal handling state ao limpar sinais pendentes
}

void	restore_parent_signals(void) // certifica-se que o child process se comporta consistentemente com o parent
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL); // applica as configurações dos sinais ao SIGINT e SIGQUIT
	sigaction(SIGQUIT, &sa, NULL);
}

void	handle_child_exit_status(int status)
{
	int	signal;

	if (WIFSIGNALED(status)) // verifica se a child terminou por causa de um sinal
	{
		signal = WTERMSIG(status); // macro que sevolve true se tiver (status é exit status do child process)
		if (signal == SIGINT)
			write(1, "\n", 1);
		else if (signal == SIGQUIT)
			write(STDERR_FILENO, "Quit (core dumped)\n", 20); // mensagem standard
	}
}

// // Main function for testing
// int	main(void)
// {
// 	char *input;
// 	setup_signals(1, 0);
// 	while (1)
// 	{
// 		input = readline("minishell> ");
// 		if (!input)
// 		{
// 			write(1, "exit\n", 5);
// 			break ;
// 		}
// 		if (strcmp(input, "heredoc") == 0)
// 		{
// 			printf("Starting heredoc...\n");
// 			handle_heredoc("EOF");
// 			printf("Heredoc finished.\n");
// 		}
// 		else
// 			printf("You entered: %s\n", input);
// 		free(input);
// 	}
// 	return (0);
// }
