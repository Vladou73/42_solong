/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:22:12 by vnafissi          #+#    #+#             */
/*   Updated: 2021/11/25 12:31:58 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Écrit la chaine de caractères ’s’ sur le file
//descriptor donné.

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}
