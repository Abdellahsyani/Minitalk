/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:44:44 by asyani            #+#    #+#             */
/*   Updated: 2025/02/26 13:26:21 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

static void	ft_convert_to_binary(int pid, int c)
{
	int	i;
	unsigned int	bit;

	i = 7;
	while (1)
	{
		bit = ((c >> i) & 1);
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		if (i == 0)
			break ;
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3 || av[2][0] == '\0')
		return (1);
	i = 0;
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		ft_convert_to_binary(pid, av[2][i]);
		i++;
	}
}
