/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:42:21 by lottavi           #+#    #+#             */
/*   Updated: 2023/05/26 16:07:28 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static int	ft_calc_num_str(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i == 0)
			num = (str[i] - '0');
		else
			num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min++;
		i++;
	}
	if (min == 1)
		return (ft_calc_num_str(str + i) * (-1));
	return (ft_calc_num_str(str + i));
}

void	ft_scomposition(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	confirm(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("MESSAGE RECEIVED\n");
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Invalid number of parametres");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		ft_scomposition(argv[2][i], pid);
		i++;
	}
	signal(SIGUSR2, confirm);
	ft_scomposition('\0', pid);
	ft_scomposition('\n', pid);
	return (0);
}
