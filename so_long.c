/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:38:12 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/23 18:04:38 by vnafissi         ###   ########.fr       */
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

void	update_window(t_game *game)
{
	int i;
	int	j;
	
	i = 0;
	while (i < game->nb_rows)
	{
		j = 0;
		while (j < game->nb_cols)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, ft_chose_img(game, game->map[i][j]), j * 50, i * 50);
			if (game->map[i][j] == 'P')
			{
				game->player_pos[0] = j;
				game->player_pos[1] = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit_pos[0] = j;
				game->exit_pos[1] = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_update_put_moves(t_game *game)
{
	game->count_moves++;
	ft_putnbr_fd(game->count_moves, 1);
	ft_putstr_fd("\n", 1);
}

int	handle_keys(int key_symb, t_game *game)
{	
	if (key_symb == KEY_UP)
		handle_key_up(game);
	if (key_symb == KEY_DOWN)
		handle_key_down(game);
	if (key_symb == KEY_LEFT)
		handle_key_left(game);
	if (key_symb == KEY_RIGHT)
		handle_key_right(game);
	if (key_symb == KEY_ESC || key_symb == RED_CROSS)
		clear_program(game);
	return 0;
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

	game.count_moves = 0;
	game.count_collectibles = 0;
	game.collected_collectibles = 0;
	
	use_minilibx(&game);

	//printf("player_pos x=%d, y=%d", game->player_pos[0], game->player_pos[1]);

	//4) Règles pour faire bouger le perso et rendre dynamique l'affichage de la map
		//use event handler and hooks https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx


	//6) Gérer l'arrêt du programme, les leaks

		//1st : mlx_destroy_display
		//2nd : free
	return (0);
}