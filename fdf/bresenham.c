/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:51:47 by chorse            #+#    #+#             */
/*   Updated: 2022/03/05 13:22:01 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z, fdf *data)
{
	*x = (*x - *y) * cos(data->angle_cos);
	*y = (*x + *y) * sin(data->angle_sin) - z;
}

void	get_color(int z, int z1, fdf *data)
{
	if (z > -9 || z1 > -9)
		data->color = 0x00FF00;
	if (z > -7 || z1 > -7)
		data->color = 0xCAFFCA;
	if (z > -5 || z1 > -5)
		data->color = 0xACFFAC;
	if (z > -3 || z1 > -3)
		data->color = 0x97FF97;
	if (z > -1 || z1 > -1)
		data->color = 0x5CFF5C;
	if (z == 0 || z1 == 0)
		data->color = 0x00CC00;
	if (z > 1 || z1 > 1)
		data->color = 0x00A300;
	if (z > 3 || z1 > 3)
		data->color = 0x008200;
	if (z > 5 || z1 > 5)
		data->color = 0x006800;
	if (z > 7 || z1 > 7)
		data->color = 0xA30000;
	if (z > 9 || z1 > 9)
		data->color = 0xCC0000;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	get_color(z, z1, data);
	x *= data->zoom;
	y *= data->zoom;
	z *= data->z_scale;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z1 *= data->z_scale;
	if (data->flag)
	{
		ft_isometric(&x, &y, z, data);
		ft_isometric(&x1, &y1, z1, data);
	}
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
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

void	draw(fdf *data)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_mod(float a)
{
	if (a < 0)
		return (-1 * a);
	else
		return (a);
}

