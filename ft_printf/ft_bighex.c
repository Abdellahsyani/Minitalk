/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_HEX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:56:13 by asyani            #+#    #+#             */
/*   Updated: 2024/11/17 12:57:19 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_hexadecimal - the function that print hexadecimal
 * @n: the number that we will print
 *
 * return: how many number we print
 */

int	ft_hexadecimal(unsigned int n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_hexadecimal(n / 16);
	}
	ft_putchar(hex[n % 16]);
	return (count + 1);
}
