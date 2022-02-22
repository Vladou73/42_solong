
#include "./includes/so_long.h"
#include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
  #include <fcntl.h>

//Votre programme doit prendre en paramètre un fichier de carte se terminant par l’extension .ber.

//Uniquement 5 caractères acceptés pour la carte :
// 0 pour un emplacement vide,
// 1 pour un mur,
// C pour un item à ramasser (c pour collectible),
// E pour une sortie,
// P pour la position de départ du personnage.

//Cas d'erreurs : le programme doit quitter proprement et retourner "Error\n" suivi d’un message d’erreur explicite.
	// La carte doit être fermée en étant encadrée par des murs.
	// La carte doit contenir au moins une sortie (E), un item (C), et une position de départ (P). A voir comment je traite si il y a plusieurs points de départ et plusieurs points de sortie
	// La carte doit être de forme rectangulaire.
	// Uniquement 5 caractères acceptés : 0, 1, C, E, P


int	main(void)
{
	//0) Open map file
	char    **map;
    int     fd;
    char    *row;
    char    str_map[100000];
    int     len_file;

    map = NULL;
	
    //1) open map & read file
    fd = open("./map.txt", O_RDONLY);
    len_file = read(fd, str_map, 100000);
    str_map[len_file] = 0;

    //2) split string into char **
    map = ft_split(str_map, '\n');
    
    int i = 0;
    while (map[i])
    {
	    printf("%s\n", map[i]);
        i++;
    }
    
	//2) Vérifications que la map soit ok

	close(fd);
	return (0);

}