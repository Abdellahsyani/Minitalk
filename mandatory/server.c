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

static void	design(void)
{
	ft_printf("\033[1;94m");
	ft_printf("\n");
	ft_printf("   ██████ ███████ ██████  ██    ██ ███████ ██████   \n");
	ft_printf("  ██      ██      ██   ██ ██    ██ ██      ██   ██  \n");
	ft_printf("   █████  █████   ██████  ██    ██ █████   ██████   \n");
	ft_printf("       ██ ██      ██   ██  ██  ██  ██      ██   ██  \n");
	ft_printf("  ██████  ███████ ██   ██   ████   ███████ ██   ██  \n");
	ft_printf("\033[0m\n");
	ft_printf("\033[1;36m───────────────────────────────────\033[0m\n");
	ft_printf("\033[1;92m\033[5m");
	ft_printf("  ➤ Server is Running...\n");
	ft_printf("\033[0m");
	ft_printf("\033[1;93m");
	ft_printf("  ➤ Server PID : %d\n", getpid());
	ft_printf("\033[0m");
	ft_printf("\033[1;36m───────────────────────────────────\033[0m\n");
}

/**
 * sig_handler _ the function that handle signals
 */
static void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	bit_arr;
	static int				bit_count;
	static pid_t			client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		bit_arr = 0;
		bit_count = 0;
	}
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

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	design();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
