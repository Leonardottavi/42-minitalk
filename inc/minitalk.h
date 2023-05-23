/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:42:50 by lottavi           #+#    #+#             */
/*   Updated: 2023/05/23 11:39:32 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

# define TIME_SLEEP 1000

typedef struct s_unicode
{
	int			bit;
	char		uni_char;
}				t_unicode;

#endif
