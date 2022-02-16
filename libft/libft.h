/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimir <vladimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:56:45 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/07 12:11:18 by vladimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// necessary libraries.
# include <stdlib.h>
# include <unistd.h>
// libraries for testing functions
# include <stdio.h>
# include <ctype.h>
# include <string.h>

// prototypes
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atol(const char *src);
void	ft_bzero(void *ptr, size_t n);
void	*ft_calloc(size_t n, size_t size);
void	ft_putstr_fd(char *s, int fd);
int		ft_isint(long n);
int		ft_atoi(const char *src);
int		ft_isdigit(int c);

#endif
