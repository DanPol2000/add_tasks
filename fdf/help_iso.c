

void	bresenham(float x, float y, fdf *data)
{
	float x_step;
	float y_step;
	int         max;
    int x1;
    int y1;
	
    x1 = x + 1;
    y1 = y + 1;
    x *= data->zoom;
	y *= data->zoom;
    x1 *= data->zoom;
	y1 *= data->zoom;
	x_step = x1 - x;
	y_step = y1 - y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void ft_color(float x, float y, fdf *data)
{
    int z;
	int z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	get_color(z, z1, data);
	z *= data->z_scale;
	z1 *= data->z_scale;

	if (data->flag)
	{
        ft_isometric(&x, &y, z, data);
		ft_isometric(&x1, &y1, z1, data);
	}

}


void    shift()
{
    int y1;
    int x1;

    x1 = x + 1;
    y1 = y + 1;

    x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
}