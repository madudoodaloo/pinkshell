/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:41:04 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/17 17:35:17 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

// Helper function to remove an element from an array of strings
void	remove_from_array(char **array, int index)
{
	if (!array || !array[index])
		return ;
	free(array[index]);
	while (array[index + 1])
	{
		array[index] = array[index + 1];
		index++;
	}
	array[index] = NULL;
}

// Removes a variable from both envp and export arrays
void	unset_env_var(char **envp, char **export, const char *var)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strcmp_nochr(var, envp[i], '=') == 0 || ft_strcmp(var,
				envp[i]) == 0)
		{
			remove_from_array(envp, i);
			break ; // Exit after removing the first match
		}
		i++;
	}
	i = 0;
	while (export[i])
	{
		if (ft_strcmp_nochr(var, export[i], '=') == 0 || ft_strcmp(var,
				export[i]) == 0)
		{
			remove_from_array(export, i);
			break ; // Exit after removing the first match
		}
		i++;
	}
}

// Main unset function
void	exec_unset(char **envp, char **export, char **args, int *exit_status)
{
	int	i;

	if (!args || !envp || !export)
		return ;
	i = 1;
	while (args[i])
	{
		unset_env_var(envp, export, args[i]);
		i++;
	}
	*exit_status = 0;
}

// Helper function to count the number of elements in an array
int	input_size(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

// Reads the unset command and processes the arguments
void	read_unset(char **envp, char **export, char **cmds, int *exit_status)
{
	int i;
	int len;
	char *buffer;

	i = 1;
	len = input_size(cmds);
	while (i < len)
	{
		buffer = ft_strdup(cmds[i]);
		unset_env_var(envp, export, buffer);
		free(buffer);
		i++;
	}
	*exit_status = 0;
}

// // funcs for the main
// char *ft_strdup(const char *str)
// {
//     char *dup = malloc(strlen(str) + 1);
//     if (dup)
//         strcpy(dup, str);
//     return dup;
// }

// // Helper function to print an array of strings
// void print_array(char **array, const char *name)
// {
//     printf("%s:\n", name);
//     for (int i = 0; array[i]; i++)
//     {
//         printf("  %s\n", array[i]);
//     }
//     if (!array[0])
//         printf("  (empty)\n");
// }

// void free_array(char **array)
// {
//     for (int i = 0; array[i]; i++)
//     {
//         free(array[i]);
//     }
// }

// int main(void)
// {
//     // Initialize environment variables (dynamically allocated)
//     char *envp[] = {
//         ft_strdup("HOME=/home/user"),
//         ft_strdup("PATH=/usr/bin"),
//         ft_strdup("USER=john"),
//         NULL
//     };

//     // Initialize exported variables (dynamically allocated)
//     char *export[] = {
//         ft_strdup("HOME=/home/user"),
//         ft_strdup("PATH=/usr/bin"),
//         NULL
//     };

//     // Initialize command arguments (no need to dynamically allocate)
//     char *args[] = {
//         "unset", // Command name
//         "HOME",  // Argument 1
//         "PATH",  // Argument 2
//         NULL
//     };

//     // Exit status
//     int exit_status;

//     // Print initial state
//     printf("Before exec_unset:\n");
//     print_array(envp, "envp");
//     print_array(export, "export");

//     // Call exec_unset
//     exec_unset(envp, export, args, &exit_status);

//     // Print final state
//     printf("\nAfter exec_unset:\n");
//     print_array(envp, "envp");
//     print_array(export, "export");
//     printf("Exit status: %d\n", exit_status);

//     // Free dynamically allocated memory
//     free_array(envp);
//     free_array(export);

//     return 0;
// }
