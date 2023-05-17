/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:55:52 by lottavi           #+#    #+#             */
/*   Updated: 2023/05/05 16:01:07 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ain(int argc, char **argv)
{
	pid_t	srv_pid;

	if (argc != 2)
		return (write(1, "usage: client <PID>\n", 21) != 0);
}
