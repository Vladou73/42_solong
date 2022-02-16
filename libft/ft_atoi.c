/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:35:57 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/01 12:22:14 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The atoi() function converts the initial portion 
//of the string pointed to by src to int.

#include "libft.h"

int	ft_atoi(const char *src)
{
	int	dest;
	int	sign;

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
