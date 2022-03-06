/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:51:47 by chorse            #+#    #+#             */
/*   Updated: 2022/03/06 18:37:13 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static float	ft_mod(float a)
{
	if (a < 0)
		return (-1 * a);
	else
		return (a);
}

static void	ft_isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle_cos);
	*y = (*x + *y) * sin(data->angle_sin) - z;
}

void	bresenham(t_dot *p, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	p->z = data->z_matrix[(int)p->y][(int)p->x];
	p->z1 = data->z_matrix[(int)p->y1][(int)p->x1];
	get_color(p, data);
	zoom(p, data);
	if (data->flag)
	{
		ft_isometric(&p->x, &p->y, p->z, data);
		ft_isometric(&p->x1, &p->y1, p->z1, data);
	}
	shift(p, data);
	x_step = p->x1 - p->x;
	y_step = p->y1 - p->y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	pixel_put(data, p, x_step, y_step);
}

void	draw(t_fdf *data)
{
	t_dot	*p;
	int		x;
	int		y;

	x = 0;
	y = 0;
	p = malloc(sizeof(t_dot));
	if (!p)
		return ;
	ft_bzero(data->addr, data->scr_y * data->scr_x * \
		(data->bits_per_pixel / 8));
	action(data, x, y, p);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	free(p);
	print_menu(data);
}
