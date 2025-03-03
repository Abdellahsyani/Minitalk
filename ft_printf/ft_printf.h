/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:15:18 by asyani            #+#    #+#             */
/*   Updated: 2024/11/18 10:15:43 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_hexa(unsigned int n);
int	ft_hexadecimal(unsigned int n);
int	ft_unsigned(unsigned int n);
int	ft_addr(void *v);

#endif
