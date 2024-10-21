/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:39:58 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/21 17:07:32 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void int_part(int num, int fd)
{
    if (num < 0)
	{
        ft_putchar_fd('-', fd);
        num = -num;
    }
    if (num / 10)
        int_part(num / 10, fd);
    ft_putchar_fd(num % 10 + '0', 1);
}

void ft_putdec_fd(double num, int fd)
{
	int integerPart;
	double fractionalPart;
	int i;
	int digit;

    if (num < 0)
	{
        ft_putchar_fd('-', fd);
        num = -num;
    }
    integerPart = (int)num;
    fractionalPart = num - integerPart;
    int_part(integerPart, fd);
    ft_putchar_fd('.', fd);
	i = 0;
    while (i < 4)
	{
        fractionalPart *= 10;
        digit = (int)fractionalPart;
        ft_putchar_fd(digit + '0', fd);
        fractionalPart -= digit;
		i++;
    }
}

