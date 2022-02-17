/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:38:12 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/17 18:22:00 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

// À chaque mouvement, le compte total de mouvement doit être affiché dans le shell
//W = haut, A = gauche, S = bas, D=droite


//coder les 4 directions de déplacement : haut, bas, gauche,droite.

// Le joueur ne doit pas pouvoir se déplacer dans les murs.

//afficher une image dans une fenêtre


//Fermeture/quitter le programme proprement
	//Appuyer sur la touche ESC doit fermer la fenêtre
	//Cliquer sur la croix en haut de la fenêtre

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


void	clear_program(void *mlx_ptr, void *win_ptr) {

	mlx_clear_window(mlx_ptr, win_ptr);
	//mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}

void	use_minilibx()
{
	t_game	game;

	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return ;
	game.win_ptr = mlx_new_window(game.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	if (game.win_ptr == NULL)
	{
		free(game.win_ptr);
		return ;
	}
	
	//void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
	//int mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );
	game.img_player = mlx_xpm_file_to_image(game.mlx_ptr, "./assets/player.xpm", &game.img_width, &game.img_height);
	printf("success=%d\n",mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_player, 50, 50));


	game.img_wall = mlx_xpm_file_to_image(game.mlx_ptr, "./assets/wall.xpm", &game.img_width, &game.img_height);
	printf("success=%d\n",mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_wall, 0, 0));

	mlx_loop(game.mlx_ptr);

	//clear_program(mlx_ptr, win_ptr);
}

int	main(void)
{
	//1) GNL pour parsing et récupérer la map

	//2) Vérifications que la map soit ok

	//3) Récupération des images pour notre carte avec la minilibx
		//A) Initialisation du programme
		use_minilibx();
		//B) Faire des boucles pour 
	//4) Reproduire la map récupérée avec gnl et l'ouvrir dans une fenêtre avec la minilibx
		//https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx
	//5) Règles pour faire bouger le perso et rendre dynamique l'affichage de la map
		//use event handler and hooks https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx


	//6) Gérer l'arrêt du programme, les leaks

		//1st : mlx_destroy_display
		//2nd : free

}