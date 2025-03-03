/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:32:42 by asyani            #+#    #+#             */
/*   Updated: 2024/11/17 11:39:56 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * helper - this function is a helper for convert int
 * @n: the number to print
 */

static int	helper(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += helper(n / 10);
	}
	ft_putchar(n % 10 + '0');
	return (count + 1);
}

/**
 * ft_integers - function that print all int
 * @n: the integer that will print
 */

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		count += helper(-n);
	}
	else
		count += helper(n);
	return (count);
}
