/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimir <vladimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:49:18 by vladimir          #+#    #+#             */
/*   Updated: 2022/02/21 20:30:33 by vladimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
#include <fcntl.h>


//buffer for get_next_line
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}


static int search_nl(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while(s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static void	update_buffer(char *buffer)
{
	int	i = 0;
	int	j = search_nl(buffer);

	if (j == 0)
	{
		buffer[0] = 0;
		return ;
	}
	while (buffer[j])
	{
		buffer[i] = buffer[j];
		j++;
		i++;
	}
	buffer[i] = 0;
}

static char *ft_strjoin_gnl(char *s1, char *s2)
{
	int	i = 0;
	int j = 0;
	char *new_s = NULL;
	if (!s2)
		return NULL;
	if (search_nl(s2))
		new_s = malloc(sizeof(char) * (ft_strlen(s1) + search_nl(s2) + 1));
	else
		new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	while (s1 && s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		new_s[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
	{
		new_s[i + j] = '\n';
		j++;
	}
	new_s[i + j] = 0;
	return new_s;
}

char	*get_next_line(int fd)
{
	//1) declare 4 variables
	static	char buffer[BUFFER_SIZE + 1];
	char	*line = NULL;
	char	*tmp = NULL;
	int		ret = 0;

	//2) check fd is readable
	if (read(fd, buffer, 0) == -1)
		return (NULL);

	//3) init line by joining buffer
	if (buffer[0])
		line = ft_strjoin_gnl(line, buffer);

	//4) while loop : while there is no newline in buffer
	while (!search_nl(buffer))
	{
		//a) read fd
		ret = read(fd, buffer, BUFFER_SIZE);
		//b) check ret has sthg. if not, update buffer, return line
		if (ret == 0)
		{
			update_buffer(buffer);
			return (line);
		}
		//c) add null char to buffer
		buffer[ret] = '\0';
		//c) tmp, join on line, free
		tmp = line;
		line = ft_strjoin_gnl(line, buffer);
		free(tmp);
	}
	//5) update buffer
	update_buffer(buffer);
	//6) return line
	return (line);
}
