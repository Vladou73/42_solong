
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:34:49 by vnafissi          #+#    #+#             */
/*   Updated: 2021/12/02 18:30:26 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Alloue (avec malloc(3)) et retourne une nouvelle
// chaine, résultat de la concaténation de s1 et s2.
// valeur de retour : La nouvelle chaine de caractères.
// NULL si l’allocation échoue.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	dst_size;

	dst_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(sizeof(char) * dst_size);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, dst_size);
	ft_strlcat(dst, s2, dst_size);
	return (dst);
}