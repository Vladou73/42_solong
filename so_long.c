/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:38:12 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/24 17:46:38 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
//Fermeture/quitter le programme proprement
	//Appuyer sur la touche ESC doit fermer la fenêtre
	//Cliquer sur la croix en haut de la fenêtre

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
	int	i;
	int	j;

	i = 0;
	while (i < game->nb_rows)
	{
		j = 0;
		while (j < game->nb_cols)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				ft_chose_img(game, game->map[i][j]), j * 50, i * 50);
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

int	ft_check_args(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		return (0);
	len = (int)ft_strlen(argv[1]);
	if (len < 4)
		return (0);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
		return (0);
	return (1);
}

//Cas d'erreurs : le programme doit quitter proprement
//et retourner "Error\n" suivi d’un message d’erreur explicite.
//6) Gérer l'arrêt du programme, les leaks
	//1st : mlx_destroy_display
	//2nd : free
int	main(int argc, char **argv)
{
	t_game	game;
	char	str_map[100000];

	if (!ft_check_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	game.map = ft_split(ft_read_map(str_map, argv[1]), '\n');
	game.nb_rows = 0;
	while (game.map[game.nb_rows])
		game.nb_rows++;
	game.nb_cols = (int)ft_strlen(game.map[0]);
	if (!ft_map_is_ok(game.map, game.nb_rows, game.nb_cols))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	game.count_moves = 0;
	game.count_collectibles = 0;
	game.collected_collectibles = 0;
	use_minilibx(&game);
	system("leaks so_long");
	return (0);
}
