/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:31:25 by asyani            #+#    #+#             */
/*   Updated: 2024/11/17 13:54:42 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * nada_nada - the check function for each specifier
 * @format: the string that we will check
 * @i: the index of each character
 * @args: the args that will go through the string
 *
 * return: length of the character that we print
 */

int	nada_nada(const char *format, int i, va_list args)
{
	int	counts;

	counts = 0;
	if (format[i] == 'd' || format[i] == 'i')
		counts += ft_putnbr(va_arg(args, int));
	else if (format[i] == 's')
		counts += ft_putstr(va_arg(args, char *));
	else if (format[i] == 'c')
		counts += ft_putchar(va_arg(args, int));
	else if (format[i] == 'x')
		counts += ft_hexa(va_arg(args, long));
	else if (format[i] == 'X')
		counts += ft_hexadecimal(va_arg(args, long));
	else if (format[i] == 'u')
		counts += ft_unsigned(va_arg(args, unsigned int));
	else if (format[i] == 'p')
	{
		counts += ft_addr(va_arg(args, void *));
	}
	else if (format[i] == '%')
		counts += ft_putchar('%');
	return (counts);
}

/**
 * ft_printf - the printf function it will print any specifier
 * @format: the string that we will handle
 * 
 * return: the length of character that we print
 */

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counts;

	i = 0;
	counts = 0;
	if (!format)
		return (0);
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			counts += nada_nada(format, i, args);
		}
		else
			counts += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (counts);
}
