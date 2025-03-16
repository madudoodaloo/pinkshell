/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:40:50 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/16 15:33:39 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// ficou igual i'm sorry não consigo mm pensar noutra forma de fazer isto mas é tão básico que não deve haver stress
char	*find_env_value(char **env, const char *var)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (var[j] && var[j] == env[i][j])
			j++;
		if (!var[j] && env[i][j] == '=')
			return (&env[i][j + 1]);
		i++;
	}
	return (NULL);
}
// caguei no get current directory e fiz merge com a change directory original
// esta é só proteção para se der erro 
static int	change_dir(const char *path)
{
	if (chdir(path) == -1)
	{
		perror("cd: chdir() error");
		return (-1);
	}
	return (0);
}

// esta ficou também a dar handle de erros de getcwd e chdir e deixou de depender de outras mini func auxiliares
void	change_directory(char **env, const char *path)
{
	char	old_pwd[PATH_MAX];
	char	new_pwd[PATH_MAX];

	if (getcwd(old_pwd, sizeof(old_pwd)) == NULL)
	{
		perror("cd: getcwd() error");
		return ;
	}
	if (!path)
	{
		path = find_env_value(env, "HOME");
		if (!path)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return ;
		}
	}
	if (change_dir(path) == -1)
		return ;
	if (getcwd(new_pwd, sizeof(new_pwd)) == NULL)
	{
		perror("cd: getcwd() error");
		return ;
	}
	printf("Changed directory from %s to %s\n", old_pwd, new_pwd);
}

// acrescentei proteção para demasiados args 
void	cd_command(char **env, char **args)
{
	const char	*path;

	if (args[1] && args[2])
	{
		write(STDERR_FILENO, "cd: too many arguments\n", 23);
		return ;
	}
	if (args[1] != NULL)
		path = args[1];
	else
		path = NULL;
	change_directory(env, path);
}

// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
//
// int main(void)
// {
//     // Simulate environment variables
//     char *env[] = {
//         "HOME=/Users/marianamestre",
//         "PWD=/Users/marianamestre/Documents/42/minishell/src/builtins",
//         NULL
//     };

//     // Simulate command line arguments
//     char *args1[] = { "cd", NULL }; // cd
//     char *args2[] = { "cd", "Documents", NULL }; // cd Documents
//     char *args3[] = { "cd", "nonexistent_directory", NULL };
	// cd nonexistent_directory
//     char *args4[] = { "cd", "arg1", "arg2", NULL };
	// cd arg1 arg2 (should fail)

//     // Test case 1: cd (should change to HOME directory)
//     printf("Test case 1: cd\n");
//     cd_command(env, args1);
//     char cwd1[PATH_MAX];
//     if (getcwd(cwd1, sizeof(cwd1))) {
//         printf("Current directory: %s\n", cwd1);
//     } else {
//         perror("getcwd() error");
//     }

//    
	// Test case 2: cd Documents (should change to Documents directory if it exists)
//     printf("\nTest case 2: cd Documents\n");
//     cd_command(env, args2);
//     char cwd2[PATH_MAX];
//     if (getcwd(cwd2, sizeof(cwd2))) {
//         printf("Current directory: %s\n", cwd2);
//     } else {
//         perror("getcwd() error");
//     }

//    
	// Test case 3: cd nonexistent_directory (should fail and stay in the same directory)
//     printf("\nTest case 3: cd nonexistent_directory\n");
//     cd_command(env, args3);
//     char cwd3[PATH_MAX];
//     if (getcwd(cwd3, sizeof(cwd3))) {
//         printf("Current directory: %s\n", cwd3);
//     } else {
//         perror("getcwd() error");
//     }

//     // Test case 4: cd arg1 arg2 (should fail due to too many arguments)
//     printf("\nTest case 4: cd arg1 arg2\n");
//     cd_command(env, args4);
//     char cwd4[PATH_MAX];
//     if (getcwd(cwd4, sizeof(cwd4))) {
//         printf("Current directory: %s\n", cwd4);
//     } else {
//         perror("getcwd() error");
//     }

//     return (0);
// }
