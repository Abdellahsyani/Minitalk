/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:38:42 by asyani            #+#    #+#             */
/*   Updated: 2025/03/03 07:38:55 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	banner_design(void)
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
 * @sig: the signal that will handled
 * @info: a struct that let us catch the pid of the client
 * @context: */
static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned int	bit_arr;
	static int			bit_count;
	static pid_t		client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		bit_arr = 0;
		bit_count = 0;
	}
	bit_arr <<= 1;
	if (sig == SIGUSR2)
		bit_arr |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (bit_arr == '\0')
			kill(client_pid, SIGUSR1);
		else
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
	banner_design();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
