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


static void sig_handler(int signal)
{
	static unsigned int	bit_arr;
	static int	bit_count;

	bit_arr <<= 1;
	if (signal == SIGUSR2)  
		bit_arr |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", bit_arr);
		bit_arr = 0;   
		bit_count = 0; 
	}
}

int	main()
{
	pid_t	pid;
	struct	sigaction sa;

	sa.sa_handler = sig_handler;

	sigemptyset(&sa.sa_mask);

	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);

	pid = getpid();
	printf("pid server: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1) 
		pause();
	return (0);
}
