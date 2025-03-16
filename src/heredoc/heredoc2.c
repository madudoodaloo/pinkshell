/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:13:48 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/16 20:36:13 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler_set_temp_filename(char *filename)
{
	static char	*temp_filename = NULL;

	if (temp_filename)
		free(temp_filename);
	temp_filename = filename;
}

// Function to generate a unique temporary filename
char	*generate_temp_filename(void)
{
	char	*filename;
	int		pid;
	time_t	now;
	char	pid_str[20];
	char	time_str[20];

	filename = malloc(256);
	if (!filename)
		return (NULL);
	pid = getpid();
	now = time(NULL);
	int_to_str(pid, pid_str);
	int_to_str((int)now, time_str);
	strcpy(filename, "/tmp/minishell_heredoc_");
	strcat(filename, pid_str);
	strcat(filename, "_");
	strcat(filename, time_str);
	return (filename);
}

// Function to create a temporary file
int	create_temp_file(char *temp_filename)
{
	int	fd;

	fd = open(temp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Failed to create temporary file\n", 38);
		free(temp_filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

// Function to redirect the temporary file to STDIN
void	redirect_temp_file_to_stdin(char *temp_filename)
{
	int	fd;

	fd = open(temp_filename, O_RDONLY); // abre o ficheiro
	if (fd == -1) // se der erro a abrir
	{
		write(STDERR_FILENO, "Error: Failed to open temporary file\n", 37);
		unlink(temp_filename); // apaga o ficheiro temporario
		free(temp_filename);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO); // duplica o fd para o stdin para qualquer tentativa de ler do stdin (terminal) seja redirecionada para o fd
	close(fd);
}

void	handle_heredoc(char *delimiter)
{
	int		fd;
	char	*temp_filename;

	setup_signals(); // configura os sinais especificamente para o heredoc
	msdata()->is_heredoc = 1; // flag para indicar que esta em heredoc
	temp_filename = generate_temp_filename(); // cria o nome para o temporary file
	if (!temp_filename) // error management
	{
		write(STDERR_FILENO, "Error: Failed to allocate memory\n", 33);
		exit(EXIT_FAILURE);
	}
	signal_handler_set_temp_filename(temp_filename); // vem para aqui para dar cleanup em caso de SIGINT
	fd = create_temp_file(temp_filename); // cria o temporary file com o nome que ja foi criado
	read_until_delimiter(fd, delimiter); // lê o input ate ao delimitador e escreve para o temp file
	close(fd);
	redirect_temp_file_to_stdin(temp_filename); // redireciona o conteudo do temporary file para o stdin
	unlink(temp_filename);
	free(temp_filename);
	msdata()->is_heredoc = 0; // flag a dizer que já não está dentro de heredoc mode
	setup_signals(); // restora os default signal handlers
}

// int	main(int argc, char **argv)
// {
// 	if (argc < 2)
// 	{
// 		write(STDERR_FILENO, "Usage: ./a.out <delimiter>\n", 27);
// 		exit(EXIT_FAILURE);
// 	}

// 	// Handle heredoc
// 	handle_heredoc(argv[1]);

// 	// Execute the command (e.g., "cat")
// 	execlp("cat", "cat", NULL);

// 	// If execlp fails
// 	write(STDERR_FILENO, "Error: Failed to execute command\n", 33);
// 	exit(EXIT_FAILURE);
// }
