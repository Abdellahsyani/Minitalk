/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:59:38 by asyani            #+#    #+#             */
/*   Updated: 2024/11/17 14:01:13 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_unsigned - print unsigned int numbers
 * @n: the number that will print
 *
 * return: how many number we print
 */

int	ft_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_unsigned(n / 10);
	}
	ft_putchar(n % 10 + '0');
	return (count + 1);
}
