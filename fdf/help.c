/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:44:52 by chorse            #+#    #+#             */
/*   Updated: 2022/03/06 16:11:27 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	file_check(char *file_name)
{
	int	i;
	int	size;

	size = ft_strlen(file_name);
	i = size - 4;
	if (file_name[i++] != '.')
		return (1);
	if (file_name[i++] != 'f')
		return (1);
	if (file_name[i++] != 'd')
		return (1);
	if (file_name[i++] != 'f')
		return (1);
	return (0);
}

void	get_color(t_dot *p, t_fdf *data)
{
	if (p->z > -9 || p->z1 > -9)
		data->color = 0x00FF00;
	if (p->z > -7 || p->z1 > -7)
		data->color = 0xCAFFCA;
	if (p->z > -5 || p->z1 > -5)
		data->color = 0xACFFAC;
	if (p->z > -3 || p->z1 > -3)
		data->color = 0x97FF97;
	if (p->z > -1 || p->z1 > -1)
		data->color = 0x5CFF5C;
	if (p->z == 0 || p->z1 == 0)
		data->color = 0x00CC00;
	if (p->z > 1 || p->z1 > 1)
		data->color = 0x00A300;
	if (p->z > 3 || p->z1 > 3)
		data->color = 0x008200;
	if (p->z > 5 || p->z1 > 5)
		data->color = 0x006800;
	if (p->z > 7 || p->z1 > 7)
		data->color = 0xA30000;
	if (p->z > 9 || p->z1 > 9)
		data->color = 0xCC0000;
}

void	init_img(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1800, 1000, "fdf");
	data->img = mlx_new_image(data->mlx_ptr, data->scr_x, data->scr_y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
										&data->line_length, &data->endian);
}

void	get_x(t_dot *p, int x, int y)
{
	p->x1 = x + 1;
	p->y1 = y;
	p->x = x;
	p->y = y;
}

void	get_y(t_dot *p, int x, int y)
{
	p->x1 = x;
	p->y1 = y + 1;
	p->x = x;
	p->y = y;
}
