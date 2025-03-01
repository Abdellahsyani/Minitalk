/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:52:03 by asyani            #+#    #+#             */
/*   Updated: 2025/02/26 15:55:51 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_convert(unsigned int bit)
{
	int	i;
	static unsigned char	c;

	i = 0;
	while (i < 8)
	{
		c = ((bit << i) | 1);
		i++;
	}
	printf("%c\n", c);
}

void	sig_handler(int	signal)
{
	static unsigned int	bit_arr;

	if (signal == SIGUSR1)
		bit_arr += 0;
	if (signal == SIGUSR2)
		bit_arr += 1;
	if (bit_arr == 8)
		ft_convert(bit_arr);
}

int	main()
{
	pid_t	pid;
	struct	sigaction sa;

	sa.sa_handler = sig_handler;
	pid = getpid();
	printf("pid server: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1) 
		pause();

	return (0);
}
