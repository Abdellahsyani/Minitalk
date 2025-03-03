/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:39:16 by asyani            #+#    #+#             */
/*   Updated: 2025/03/03 07:39:28 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * ft_atoi _ the function that convert from string to number
 * @str: the string that will converted
 *
 * return: the number that converted
 */
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

/**
 * ft_convert_to_binary _ function to convert to binary
 * @pid: the id of the server
 * @c: charecter that will convert to binary
 */
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

void	parse_pid(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			exit(1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3 || av[2][0] == '\0')
		return (1);
	i = 0;
	parse_pid(av[1]);
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		ft_convert_to_binary(pid, av[2][i]);
		i++;
	}
	ft_convert_to_binary(pid, '\0');
	return (0);
}
