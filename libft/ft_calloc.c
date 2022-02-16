/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:42:07 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/01 12:22:31 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// allocates memory for an array of n elements of size bytes each and returns
//  a pointer to the allocated memory.

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
