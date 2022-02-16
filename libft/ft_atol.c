/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimir <vladimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:35:57 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/07 12:05:51 by vladimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The atoi() function converts the initial portion
//of the string pointed to by src to int.

#include "libft.h"

long	ft_atol(const char *src)
{
	long	dest;
	int		sign;

	dest = 0;
	sign = 1;
	while (*src && (*src == ' ' || *src == '\r' || *src == '\v'
			|| *src == '\t' || *src == '\f' || *src == '\n'))
		src++;
	if (*src == '-' || *src == '+')
	{
		if (*src == '-')
			sign = -1;
		src++;
	}
	while (*src && *src >= 48 && *src <= 57)
	{
		dest = dest * 10 + *src - 48;
		src++;
	}
	return (sign * dest);
}
