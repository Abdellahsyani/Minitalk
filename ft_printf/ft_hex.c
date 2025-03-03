/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:18:09 by asyani            #+#    #+#             */
/*   Updated: 2024/11/17 12:28:23 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_hexa - print hexadecimal in lower case
 * @n: the number that will print as hex
 *
 * return: the count of printed numbers
 */

int	ft_hexa(unsigned int n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_hexa(n / 16);
	}
	ft_putchar(hex[n % 16]);
	return (count + 1);
}
