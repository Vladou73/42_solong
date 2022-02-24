/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:00:01 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/24 18:56:29 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

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
	if (key_symb == KEY_ESC)
		clear_program(game);
	return (0);
}

void	use_minilibx(t_game *game)
{
	init_mlx(game);
	update_window(game);
	mlx_key_hook(game->win_ptr, &handle_keys, game);
	mlx_hook(game->win_ptr, RED_CROSS, 0L, &clear_program, game);
	mlx_loop(game->mlx_ptr);
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		clear_program(game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			50 * game->nb_cols, 50 * game->nb_rows, "my game");
	if (game->win_ptr == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		clear_program(game);
	}
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/player.xpm", &(game->img_width), &(game->img_height));
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/wall.xpm", &(game->img_width), &(game->img_height));
	game->img_coll = mlx_xpm_file_to_image(
			game->mlx_ptr, "./assets/collectible.xpm",
			&(game->img_width), &(game->img_height));
	game->img_bckg = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/background.xpm", &(game->img_width), &(game->img_height));
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/exit.xpm", &(game->img_width), &(game->img_height));
}
