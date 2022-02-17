/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:38:12 by vnafissi          #+#    #+#             */
/*   Updated: 2022/02/16 15:24:30 by vnafissi         ###   ########.fr       */
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


void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	printf("y * img->line_len + x * (img->bpp / 8)=%d\n",y * img->line_len + x * (img->bpp / 8));
    printf("x=%d\n",x);
	printf("y=%d\n",y);
	printf("img->addr=%s\n",img->addr);
	printf("img->bpp / 8=%d\n",img->bpp / 8);
	
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	
	printf("pixel=%s\n",pixel);
	printf("color=%d\n",color);
	//*(int *)pixel = color;
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j, i, color);
			j++;
		}
		++i;
		break;
	}
}

int render_rect(t_data *data, t_rect rect)
{
	int	i;
	int j;

	if (data->win_ptr == NULL)
		return (1);
	i = rect.y;

	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(&(data->img), j++, i, rect.color);
			//mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render(t_data *data)
{
	//t_rect	rect;
	
	/* if window has been destroyed, we don't want to put the pixel ! */
	if (data->win_ptr == NULL)
		return (1);

	render_background(&data->img, 0xFFFFFF);


	//rect.x = 0;
	//rect.y = 0;
	//rect.height = 100;
	//rect.width = 100;
	//rect.color = 0xFF0000;

	//render_rect(data, rect);

	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}



void	clear_program(void *mlx_ptr, void *win_ptr) {

	mlx_clear_window(mlx_ptr, win_ptr);
	//mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}


void	use_minilibx()
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return ;
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return ;
	}

	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	data.img.addr = mlx_get_data_addr(&data.img.mlx_img, &bpp, &line_len, &endian);
	printf("addr=%s, bpp=%d, line_len=%d, endian=%d\n",data.img.addr, bpp, line_len, endian);
	/* Setup hooks */ 
	//mlx_loop_hook(data.mlx_ptr, &render, &data);
	//mlx_loop(data.mlx_ptr);

	//clear_program(mlx_ptr, win_ptr);
}





int	main(void)
{
	//1) GNL pour lire et récupérer la map

	//2) Vérifications que la map soit ok

	//3) Récupération des images pour notre carte avec la minilibx
			//https://harm-smits.github.io/42docs/libs/minilibx/images.html
			//https://aurelienbrabant.fr/blog

		//A) Initialisation du programme
		use_minilibx();
	//4) Reproduire la map récupérée avec gnl et l'ouvrir dans une fenêtre avec la minilibx
		//https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx
	//5) Règles pour faire bouger le perso et rendre dynamique l'affichage de la map
		//use event handler and hooks https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx


	//6) Gérer l'arrêt du programme, les leaks

		//1st : mlx_destroy_display
		//2nd : free

}