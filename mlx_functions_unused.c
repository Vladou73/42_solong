//int		bpp; /* bits per pixel */
//	int		line_len;
//	int		endian;

//	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	
//	data.img.addr = mlx_get_data_addr(&data.img.mlx_img, &bpp, &line_len, &endian);
//	printf("addr=%s, bpp=%d, line_len=%d, endian=%d\n",data.img.addr, bpp, line_len, endian);
	
		/* Setup hooks */ 
	//mlx_loop_hook(data.mlx_ptr, &render, &data);

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


