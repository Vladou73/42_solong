
#include "./includes/so_long.h"
#include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//Votre programme doit prendre en paramètre un fichier de carte se terminant par l’extension .ber.



char	*ft_read_map(char *str_map)
{
    int     len_file;
    int     fd;

    //1) open map & read file
    fd = open("./map.txt", O_RDONLY);
    len_file = read(fd, str_map, 100000);

    str_map[len_file] = 0;
	close(fd);
	return (str_map);
}

int	ft_is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	ft_char_is_ok(char c)
{
	if (c == '1' || c == '0' ||c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

// Uniquement 5 caractères acceptés : 0, 1, C, E, P
// La carte doit être fermée en étant encadrée par des murs.
int	ft_map_chars_are_ok(char **map, int nb_rows, int nb_cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_rows)
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == nb_rows || j == 0 || j == nb_cols - 1)
			{
				if (!ft_is_wall(map[i][j]))
					return (0);
			}
			else 
			{
				if (!ft_char_is_ok(map[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}


// C pour un item à ramasser (c pour collectible),
// E pour une sortie,
// P pour la position de départ du personnage.

int	ft_count_elements(char **map, int nb_rows)
{
	int	exit;
	int item;
	int start;
	int	i;

	exit = 0;
	item = 0;
	start = 0;
	while (nb_rows)
	{
		i = 0;
		while (map[nb_rows - 1][i])
		{
			if (map[nb_rows - 1][i] == 'C')
				item++;
			if (map[nb_rows - 1][i] == 'E')
				exit++;
			if (map[nb_rows - 1][i] == 'P')
				start++;
			i++;
		}
		nb_rows--;
	}
	printf("exit=%d, item=%d, start=%d\n", exit, item, start);
	if (exit != 1 || item < 1 || start != 1)
		return (0);
	return (1);
}

// La carte doit être de forme rectangulaire.
int	ft_map_is_rectangle(char **map, int nb_cols)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != nb_cols)
			return (0);
		i++;
	}
	return (1);
}

// La carte doit contenir au moins une sortie (E), un item (C), et une position de départ (P). A voir comment je traite si il y a plusieurs points de départ et plusieurs points de sortie
int	ft_map_is_ok(char **map, int nb_rows, int nb_cols)
{
	if(!ft_map_chars_are_ok(map, nb_rows, nb_cols))
		return (0);
	if(!ft_map_is_rectangle(map, nb_cols))
		return (0);
	if(!ft_count_elements(map, nb_rows))
		return (0);
	printf("map ok\n");
	return (1);
}

int	main(void)
{
	char    str_map[100000];
	char    **map;
	// char    *row;
	int		nb_rows;
	int		nb_cols;

    //1) store map data into char **
    map = ft_split(ft_read_map(str_map), '\n');
    
    nb_rows = 0;
    while (map[nb_rows])
	{
		printf("%s\n", map[nb_rows]);
		nb_rows++;
	}
	nb_cols = ft_strlen(map[0]);
    
	//2) Vérifications que la map soit ok
	if (!ft_map_is_ok(map, nb_rows, nb_cols))
	{
		//Cas d'erreurs : le programme doit quitter proprement et retourner "Error\n" suivi d’un message d’erreur explicite.
		ft_putstr_fd("Error\n",1);
		return (0);
	}
	return (0);
}