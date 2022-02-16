/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:41:51 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/02 11:57:10 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// compares at most the first n bytes 
// of the 2 strings s1 and s2. 
// It returns an integer less than, equal to, 
// or greater than zero if s1 is found, respectively,
// to be less than, to match, or be greater than s2.

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*unsigned_s1;
	unsigned char	*unsigned_s2;

	unsigned_s1 = (unsigned char *)s1;
	unsigned_s2 = (unsigned char *)s2;
	while ((*unsigned_s1 || *unsigned_s2) && n > 0)
	{
		if (*unsigned_s1 != *unsigned_s2)
			return (*unsigned_s1 - *unsigned_s2);
		unsigned_s1++;
		unsigned_s2++;
		n--;
	}
	return (0);
}
