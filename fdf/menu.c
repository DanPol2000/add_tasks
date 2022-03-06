/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:00:31 by chorse            #+#    #+#             */
/*   Updated: 2022/03/06 17:38:01 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	action(t_fdf *data, int x, int y, t_dot *p)
{
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (x < data->width - 1)
			{
				get_x(p, x, y);
				bresenham(p, data);
			}
			if (y < data->height - 1)
			{
				get_y(p, x, y);
				bresenham(p, data);
			}
		}
	}
}

void	print_menu(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Move: <- / ->");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Zoom: + / -");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Scale: Q / W");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Rotate: A / S / D / F");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "ISO ON/OFF: 1 / 2");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Reset: TAB");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Exit: ESC");
}

void	first_init(t_fdf *data)
{
	data->zoom = 30;
	data->z_scale = 2;
	data->shift_y = 250;
	data->shift_x = 900;
	data->scr_x = WIDTH;
	data->scr_y = HEIGHT;
	data->angle_cos = 0.8;
	data->angle_sin = 0.8;
	data->flag = 1;
}

void	ft_bzero(void *str, size_t n)
{
	char	*tmp;
	size_t	i;

	if (!n)
		return ;
	tmp = str;
	i = 0;
	while (i < n)
		*(tmp + i++) = 0;
}

void	pixel_put(t_fdf *data, t_dot *p, float x_step, float y_step)
{
	while ((int)(p->x - p->x1) || (int)(p->y - p->y1))
	{
		if ((int)p->x < data->scr_x && (int)p->y < data->scr_y
			&& (int)p->x >= 0 && (int)p->y >= 0)
			my_mlx_pixel_put(data, p->x, p->y, data->color);
		p->x += x_step;
		p->y += y_step;
	}
}
