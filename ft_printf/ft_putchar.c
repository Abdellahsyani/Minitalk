/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:32:02 by asyani            #+#    #+#             */
/*   Updated: 2024/11/17 11:44:59 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_putchar - printer function
 * @c: the character that will print
 */

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
