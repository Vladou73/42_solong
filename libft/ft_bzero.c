/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:38:40 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/01 12:22:22 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The bzero() function erases the data in the n bytes of the memory
// starting at the location pointed to by ptr, by writing zeros (bytes
// containing '\0') to that area.
//https://www.quora.com/Why-cant-I-perform-arithmetic-on-a-void-pointer

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	char	*s;

	s = (char *) ptr;
	while (n > 0)
	{
		s[n - 1] = 0;
		n--;
	}
}
