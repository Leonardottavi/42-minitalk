/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:01:34 by lottavi           #+#    #+#             */
/*   Updated: 2023/05/05 16:28:55 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	handlesing(int sig)
{
	if (sig == SIGUSR1)
	{
	}
	else if (sig == SIGUSR2)
	{
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	pid = getpid();
	signal(SIGUSR1, &handlesig);
	signal(SIGUSR2, &handlesig);
	ft_printf("%i\n", pid);
	return (EXIT_SUCCESS);
}
