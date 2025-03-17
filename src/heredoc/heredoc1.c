/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:18:49 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/17 00:05:49 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/heredoc.h"

/*expansão*/
const char *extract_var_name(const char *start, char *var_name)
{
    const char *var_end;
	
	var_end = start;
    while (*var_end && (ft_isalnum(*var_end) || *var_end == '_'))
        var_end++;
    ft_strncpy(var_name, start, var_end - start);
    var_name[var_end - start] = '\0';
    return (var_end);
}

char *expand_variables(const char *input)
{
	const char *start;
	char *expanded;
	char var_name[256];
	char *var_value;
	
    expanded = malloc(ft_strlen(input) + 250); // Depois ajustamos
    if (!expanded) 
		return NULL;
    expanded[0] = '\0';
    start = input;
    while (*start)
    {
        if (*start == '$')
        {
            start = extract_var_name(start + 1, var_name);
            var_value = getenv(var_name);
            if (var_value) 
				ft_strcat(expanded, var_value);
        }
        else
            ft_strncat(expanded, start++, 1);
    }
    return (expanded);
}

char	*get_delimiter(char *str, int i)
{
	char	*delimiter;
	int		k;
	int		m;

	while (str[i] == ' ')
		i++;
	k = i;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	delimiter = (char *)malloc(sizeof(char) * (i - k + 1));
	if (!delimiter)
		return (NULL);
	m = 0;
	while (k < i)
		delimiter[m++] = str[k++];
	delimiter[m] = '\0';
	return (delimiter);
}

int	heredoc_parser(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i + 1] == '<')
		{
			i += 2;
			while (str[i] == ' ')
				i++;
			if (str[i] == '\0')
				return (-1);
			return (i);
		}
		i++;
	}
	return (-1);
}

void read_until_delimiter(int fd, char *delimiter)
{
    char buffer[1024]; // quantidade standard nada de mais
    int bytes_read; // qunatidade de bytes que ja foram lidos
    int delimiter_len = ft_strlen(delimiter);
	char *expanded_input; // input ja expandido

    while (1) // lê infinitamene ate encontrar um delimitador ou der erro
    {
        write(STDOUT_FILENO, "> ", 2); // display do ">" no prompt
        bytes_read = read(STDIN_FILENO, buffer, 1023); // so le ate 1023 bytes
        if (bytes_read <= 0) // se der 0 ou menos quer dizer que ou foi EOF ou CTR+D
            break;
        buffer[bytes_read] = '\0'; // null terminates para o input ser tratado como string válida
        if (ft_strncmp(buffer, delimiter, delimiter_len) == 0 && buffer[delimiter_len] == '\n') // compara o input com o delimitador e verifica se tem \n logo  a seguir (se foi <<EOF + enter)
            break;
        expanded_input = expand_variables(buffer); // expande variaveis se for o caso
        if (!expanded_input)
        {
            write(STDERR_FILENO, "Error: Failed to expand variables\n", 33); // se nao for possivel expandir
            break;
        }
        write(fd, expanded_input, ft_strlen(expanded_input)); // escreve as expansoes para o fd
        free(expanded_input);
    }
}

// int	main(int ac, char **av)
// {
// 	int pos;
// 	char *delimiter;

// 	if (ac == 2)
// 	{
// 		pos = heredoc_parser(av[1]);
// 		if (pos == -1)
// 		{
// 			printf("No heredoc found.\n");
// 			return (1);
// 		}
// 		delimiter = get_delimiter(av[1], pos);
// 		if (!delimiter)
// 		{
// 			printf("Memory allocation failed.\n");
// 			return (1);
// 		}
// 		printf("Delimiter: '%s'\n", delimiter);
// 		free(delimiter);
// 	}
// 	return (0);
// }