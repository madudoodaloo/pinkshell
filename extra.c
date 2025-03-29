/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:21:23 by marianamest       #+#    #+#             */
/*   Updated: 2025/03/28 18:51:57 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int is_special_char(char c) 
{
    return c == '<' || c == '>' || c == '|';
}

size_t calculate_required_size(const char *input) 
{
    size_t extra;
    int i;
    
    extra = 0;
    i = 0;
    while (input[i] != '\0') 
    {
        if (is_special_char(input[i])) 
        {
            if ((input[i] == '<' && input[i+1] == '<') || (input[i] == '>' && input[i+1] == '>')) 
            {
                i++;
                if (i == 1 || input[i-2] != ' ')
                    extra++;
                if (input[i+1] != ' ')
                    extra++;
            } 
            else 
            {
                if (i == 0 || input[i-1] != ' ') 
                    extra++;
                if (input[i+1] != ' ') 
                    extra++;
            }
        }
        i++;
    }
    return (strlen(input) + extra + 1);
}

void handle_special_char(const char *input, char *output, int *i, int *j) 
{
    if ((input[*i] == '<' && input[*i + 1] == '<') || (input[*i] == '>' && input[*i + 1] == '>')) 
    {
        if (*j > 0 && output[*j - 1] != ' ')
            output[(*j)++] = ' ';
        output[(*j)++] = input[(*i)++];
        output[(*j)++] = input[*i];
        if (input[*i + 1] != ' ' && input[*i + 1] != '\0')
            output[(*j)++] = ' ';
    } 
    else if (is_special_char(input[*i]))
    {
        if (*j > 0 && output[*j - 1] != ' ')
            output[(*j)++] = ' ';
        output[(*j)++] = input[*i];
        if (input[*i + 1] != ' ' && input[*i + 1] != '\0')
            output[(*j)++] = ' ';
    } 
    else
        output[(*j)++] = input[*i];
}

char* add_spaces(const char *input) 
{
    size_t required_size = calculate_required_size(input);
    char *output = (char*)malloc(required_size * sizeof(char));
    if (output == NULL) return NULL;

    int i = 0;
    int j = 0;
    while (input[i] != '\0') {
        handle_special_char(input, output, &i, &j);
        i++;
    }
    output[j] = '\0';
    return output;
}

int main() 
{
    const char *input = "a<b|    c>>d <<e>f";
    char *output = add_spaces(input);
    printf("Input:  %s\n", input);
    printf("Output: %s\n", output);
    free(output);
    return 0;
}