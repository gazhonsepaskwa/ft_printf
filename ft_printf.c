/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:10:50 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/21 17:35:20 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

#include <stdio.h>

static void print_apropriated(const char *fstr, va_list ap)
{
    if (*fstr == 'c')
        ft_putchar_fd((char)va_arg(ap, int), 1);
    else if (*fstr == 's')
        ft_putstr_fd(va_arg(ap, char *), 1);
    // else if (*fstr == 'p')

    else if (*fstr == 'd')
        ft_putdec_fd(va_arg(ap, double), 1);
    else if (*fstr == 'i')
        ft_putnbr_fd(va_arg(ap, int), 1);
    // if (*fstr == 'u')
    // if (*fstr == 'x')
    // if (*fstr == 'X')
    // if (*fstr == '%')
    else
    {
        ft_putchar_fd('%', 1);
        ft_putchar_fd(*fstr, 1);
    }
}


int ft_printf(const char *fstr, ...)
{
    va_list ap;
    int printed_char;

    printed_char = 0;
    va_start(ap, fstr);
    while (*fstr != 0)
    {
        if (*fstr == '%')
        {
            fstr++;
            print_apropriated(fstr, ap);
        }
        else
            ft_putchar_fd(*fstr, 1);
        fstr++;
    }
    va_end(ap);
    return (printed_char);
}


int main (void)
{
    int a = 42;
    void *ptr = &a;
    ft_printf("ft_printf : {%c} {%s} {%s} {%s} ? {%i} {%d} {%p} {%p}\n", 'd', " ", "", "===", -42, 0.344, ptr, &ptr);
       printf("   printf : {%c} {%s} {%s} {%s} ? {%i} {%f} {%p} {%p}\n", 'd', " ", "", "===", -42, 0.344, ptr, &ptr);
}