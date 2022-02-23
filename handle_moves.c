/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:54:32 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/23 17:55:00 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	handle_key_up(t_game *game)
{
	if (game->player_pos[1] <= 0)
		return ;
	if (game->map[game->player_pos[1] - 1][game->player_pos[0]] == '1')
		return ;
	if (game->map[game->player_pos[1] - 1][game->player_pos[0]] == 'E')
	{
		if (!ft_no_more_collectibles(game))
			return;
	}
	game->map[game->player_pos[1]][game->player_pos[0]] = '0';
	game->player_pos[1]--;
	game->map[game->player_pos[1]][game->player_pos[0]] = 'P';
	update_window(game);
	ft_update_put_moves(game);
	ft_check_exit(game);
}

void	handle_key_down(t_game *game)
{
	if (game->player_pos[1] >= game->nb_rows -1)
		return ;
	if (game->map[game->player_pos[1] + 1][game->player_pos[0]] == '1')
		return ;
	if (game->map[game->player_pos[1] + 1][game->player_pos[0]] == 'E')
	{
		if (!ft_no_more_collectibles(game))
			return;
	}
	game->map[game->player_pos[1]][game->player_pos[0]] = '0';
	game->player_pos[1]++;
	game->map[game->player_pos[1]][game->player_pos[0]] = 'P';
	update_window(game);
	ft_update_put_moves(game);
	ft_check_exit(game);
}

void	handle_key_left(t_game *game)
{
	if (game->player_pos[0] <= 0)
		return ;
	if (game->map[game->player_pos[1]][game->player_pos[0] - 1] == '1')
		return ;
	if (game->map[game->player_pos[1]][game->player_pos[0] - 1] == 'E')
	{
		if (!ft_no_more_collectibles(game))
			return;
	}
	game->map[game->player_pos[1]][game->player_pos[0]] = '0';
	game->player_pos[0]--;
	game->map[game->player_pos[1]][game->player_pos[0]] = 'P';
	update_window(game);
	ft_update_put_moves(game);
	ft_check_exit(game);
}

void	handle_key_right(t_game *game)
{
	if (game->player_pos[0] >= game->nb_cols -1)
		return ;
	if (game->map[game->player_pos[1]][game->player_pos[0] + 1] == '1')
		return ;
	if (game->map[game->player_pos[1]][game->player_pos[0] + 1] == 'E')
	{
		if (!ft_no_more_collectibles(game))
			return;
	}
	game->map[game->player_pos[1]][game->player_pos[0]] = '0';
	game->player_pos[0]++;
	game->map[game->player_pos[1]][game->player_pos[0]] = 'P';
	update_window(game);
	ft_update_put_moves(game);
	ft_check_exit(game);
}
