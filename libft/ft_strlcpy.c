
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:38:43 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/01 12:24:42 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <bsd/string.h>
// The strlcpy() function copies up to size - 1 characters from 
// the NUL-terminated string src to dst, NUL-terminating the result.

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dst_size == 0)
		return (src_size);
	i = 0;
	while (i < dst_size - 1 && i < src_size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}