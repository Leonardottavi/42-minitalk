/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:52:11 by lottavi           #+#    #+#             */
/*   Updated: 2023/04/14 11:52:12 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	num_to_str(long nb, int i, int slen, char *str)
{
	if (nb > 9)
	{
		i++;
		num_to_str(nb / 10, i, slen, str);
		str[slen - i] = (nb % 10) + 48;
		return ;
	}
	i++;
	str[slen - i] = nb + 48;
	return ;
}

static int	numstrlen(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		slen;
	long	nb;

	nb = n;
	if (nb != 0)
		slen = numstrlen(nb);
	else
		slen = 1;
	if (nb < 0)
		nb = -nb;
	str = malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	num_to_str(nb, 0, slen, str);
	if (n < 0)
		str[0] = '-';
	str[slen] = '\0';
	return (str);
}
