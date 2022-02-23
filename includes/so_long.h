/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:38:31 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/23 18:03:00 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/stat.h>
#include <fcntl.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	void	*img_player;
	void	*img_wall;
	void	*img_bckg;
	void	*img_exit;
	void	*img_coll;
	
	int		img_width;
	int		img_height;

	int		nb_rows;
	int		nb_cols;

	char	**map;
	int		player_pos[2];
	int		exit_pos[2];
	
	int		count_moves;
	int		count_collectibles;
	int		collected_collectibles;
}	t_game;

//******************** DEFINE KEYS ********************//

#  define KEY_ESC	53
#  define KEY_UP	13
#  define KEY_RIGHT 2
#  define KEY_DOWN 	1
#  define KEY_LEFT 	0
#  define RED_CROSS	17





//******************** PARSING MAP FILE ********************//
int	ft_map_is_ok(char **map, int nb_rows, int nb_cols);
char	*ft_read_map(char *str_map);

//******************** HANDLE MOVES ********************//
void	handle_key_up(t_game *game);
void	handle_key_down(t_game *game);
void	handle_key_left(t_game *game);
void	handle_key_down(t_game *game);

//******************** USE MINILIBIX ********************//
void	use_minilibx(t_game *game);
void	init_mlx(t_game *game);



#endif