/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:11:59 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/24 20:22:56 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Alloue (avec malloc(3)) et retourne un tableau
// de chaines de caracteres obtenu en séparant ’s’ à
// l’aide du caractère ’c’, utilisé comme délimiteur.
// Le tableau doit être terminé par NULL.

#include "libft.h"

static void	exit_on_error(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
	}
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

static char	**allocate_newarray_memory(char const *s, char c)
{
	size_t		newarray_size;
	size_t		j;

	j = 0;
	newarray_size = 0;
	if (s[0] == 0)
		return (malloc(sizeof(char *) * (newarray_size + 1)));
	while (s != NULL && *s)
	{
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (j > 0)
			newarray_size++;
		s = ft_strchr(s, c);
		if (s != NULL)
			s++;
	}
	return (malloc(sizeof(char *) * (newarray_size + 1)));
}

static char	**ft_process(char **newarray, char const *s, char c)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (s != NULL && *s)
	{
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (j > 0)
		{
			newarray[i] = malloc(sizeof(char) * (j + 1));
			if (!newarray[i])
				exit_on_error(newarray);
			ft_strlcpy(newarray[i], s, j + 1);
			i++;
		}
		s = ft_strchr(s, c);
		if (s != NULL && s[0] != '\0')
			s++;
	}
	newarray[i] = NULL;
	return (newarray);
}

char	**ft_split(char const *s, char c)
{
	char	**newarray;

	if (!s)
		return (NULL);
	newarray = allocate_newarray_memory(s, c);
	if (!newarray)
		return (NULL);
	return (ft_process(newarray, s, c));
}
