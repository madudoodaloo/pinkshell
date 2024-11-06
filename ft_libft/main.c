/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabrito- <mabrito-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:09:30 by mabrito-          #+#    #+#             */
/*   Updated: 2023/11/02 11:21:17 by mabrito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int main()
{
    int fd = open("test.txt", O_WRONLY);
    char *a = " -123";
    ft_putnbr_fd(ft_atoi(a), fd);

    close(fd);
}