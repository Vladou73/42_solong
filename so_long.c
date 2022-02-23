/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:38:12 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/23 11:56:35 by vnafissi         ###   ########.fr       */
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

void	clear_program(void *mlx_ptr, void *win_ptr) {

	mlx_clear_window(mlx_ptr, win_ptr);
	//mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}


void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr, 50 * game->nb_cols, 50 * game->nb_rows, "my window");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		return ;
	}

	//void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/player.xpm", &(game->img_width), &(game->img_height));
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/wall.xpm", &(game->img_width), &(game->img_height));
	game->img_coll = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/collectible.xpm", &(game->img_width), &(game->img_height));
	game->img_bckg = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/background.xpm", &(game->img_width), &(game->img_height));
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/exit.xpm", &(game->img_width), &(game->img_height));
}

void	*ft_chose_img(t_game *game, char c)
{
	if (c == 'P')
		return (game->img_player);
	else if (c == 'C')
		return (game->img_coll);
	else if (c == '0')
		return (game->img_bckg);
	else if (c == '1')
		return (game->img_wall);
	else if (c == 'E')
		return (game->img_exit);
	return (NULL);
}

void	populate_window(t_game *game)
{
	int i;
	int	j;
	
	i = 0;
	
	//int mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );
	while (i < game->nb_rows)
	{
		j = 0;
		while (j < game->nb_cols)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, ft_chose_img(game, game->map[i][j]), j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	use_minilibx(t_game *game)
{
	init_mlx(game);
	populate_window(game);
	
	

	//printf("success=%d\n",mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, 50, 50));
	//printf("success=%d\n",mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_wall, 0, 0));

	mlx_loop(game->mlx_ptr);

	//clear_program(mlx_ptr, win_ptr);
}

int	main(void)
{
	t_game	game;
	char    str_map[100000];

    //1) read file abd parse/store map data into array of strings
   game.map = ft_split(ft_read_map(str_map), '\n');
    
    game.nb_rows = 0;
    while (game.map[game.nb_rows])
	{
		printf("%s\n", game.map[game.nb_rows]);
		game.nb_rows++;
	}
	game.nb_cols = (int)ft_strlen(game.map[0]);
    
	//2) Vérifications que la map soit ok
	if (!ft_map_is_ok(game.map, game.nb_rows, game.nb_cols))
	{
		//Cas d'erreurs : le programme doit quitter proprement et retourner "Error\n" suivi d’un message d’erreur explicite.
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	//3) Récupération des images pour notre carte avec la minilibx
		//A) Initialisation du programme
		use_minilibx(&game);
		//B) Faire des boucles pour 

	//4) Reproduire la map récupérée avec gnl et l'ouvrir dans une fenêtre avec la minilibx
		//https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx
	//5) Règles pour faire bouger le perso et rendre dynamique l'affichage de la map
		//use event handler and hooks https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx


	//6) Gérer l'arrêt du programme, les leaks

		//1st : mlx_destroy_display
		//2nd : free
	return (0);
}