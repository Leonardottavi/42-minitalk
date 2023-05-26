/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:41:52 by lottavi           #+#    #+#             */
/*   Updated: 2023/05/26 15:59:01 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void	ft_recomposition(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	output;

	(void) context;
	if (signal == SIGUSR1)
		output |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (output == 0)
			kill(info->si_pid, SIGUSR2);
		else
			ft_printf("%c", output);
		output = 0;
		bit = 0;
	}
}

int	main(int argc, char	**argv)
{
	int					pid;
	struct sigaction	act;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	pid = getpid();
	ft_printf("%d", pid);
	ft_printf("\n");
	act.sa_sigaction = ft_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
