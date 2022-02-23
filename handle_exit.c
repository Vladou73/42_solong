/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:03:55 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/23 18:04:54 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/so_long.h"


int	ft_no_more_collectibles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->nb_rows)
	{
		j = 0;
		while (j < game->nb_cols)
		{
			if (game->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


void	clear_program(t_game *game) {

	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(1);
	//mlx_clear_window(mlx_ptr, win_ptr);
	//mlx_destroy_display(mlx_ptr);
	//free(mlx_ptr);
}

//Le but du joueur est de collecter tous les items présents sur la carte, puis de
//s’échapper en empruntant le chemin le plus court possible.
void	ft_check_exit(t_game *game)
{
	if (game->exit_pos[0] == game->player_pos[0]
		&& game->exit_pos[1] == game->player_pos[1]
		&& ft_no_more_collectibles(game))
		clear_program(game);			
}
