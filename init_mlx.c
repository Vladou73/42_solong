/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:00:01 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/23 18:01:17 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	use_minilibx(t_game *game)
{
	init_mlx(game);
	update_window(game);
	mlx_key_hook(game->win_ptr, &handle_keys, game);


	mlx_loop(game->mlx_ptr);
	//clear_program(mlx_ptr, win_ptr);
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
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/player.xpm", &(game->img_width), &(game->img_height));
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/wall.xpm", &(game->img_width), &(game->img_height));
	game->img_coll = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/collectible.xpm", &(game->img_width), &(game->img_height));
	game->img_bckg = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/background.xpm", &(game->img_width), &(game->img_height));
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/exit.xpm", &(game->img_width), &(game->img_height));
}