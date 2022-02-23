/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:56:45 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/23 16:08:49 by vnafissi         ###   ########.fr       */
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

//buffer for get_next_line
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif


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
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);


#endif
