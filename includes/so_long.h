/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:38:31 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/17 18:09:22 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_player;
	void	*img_wall;
	void	*img_background;
	void	*img_exit;
	void	*img_collectible;
	
	int		img_width;
	int		img_height;
	
}	t_game;

typedef struct s_rect /* The x and y coordinates of the rect corresponds to its upper left corner. */
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;



//******************** LINKED LISTS ********************//

#endif