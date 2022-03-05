/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:03:09 by chorse            #+#    #+#             */
/*   Updated: 2022/03/05 18:48:23 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, fdf *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(key, data);
	if (key == ZOOM_UP || key == ZOOM_DOWN)
		zoom(key, data);
	if (key == ANGLE_COS_DOWN || key == ANGLE_COS_UP || key == ANGLE_SIN_DOWN \
												|| key == ANGLE_SIN_UP)
		angle(key, data);
	if (key == Z_UP || key == Z_DOWN)
		z_scale(key, data);
	if (key == ISO_ON)
		data->flag = 1;
	if (key == ISO_OFF)
		data->flag = 0;
	if (key == RESET)
		first_init(data);
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		ft_free_data_struct(data);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_menu(data);
	draw(data);
	return (0);
}

int	move(int key, fdf *data)
{
	if (key == UP)
		data->shift_y -= 50;
	if (key == DOWN)
		data->shift_y += 50;
	if (key == LEFT)
		data->shift_x -= 50;
	if (key == RIGHT)
		data->shift_x += 50;
	return (0);
}

int	zoom(int key, fdf *data)
{
	if (key == ZOOM_UP)
		data->zoom += 1;
	if (key == ZOOM_DOWN)
		data->zoom -= 1;
	return (0);
}

int	angle(int key, fdf *data)
{
	if (key == ANGLE_COS_UP)
		data->angle_cos += 0.01;
	if (key == ANGLE_COS_DOWN)
		data->angle_cos -= 0.01;
	if (key == ANGLE_SIN_UP)
		data->angle_sin += 0.01;
	if (key == ANGLE_SIN_DOWN)
		data->angle_sin -= 0.01;
	return (0);
}

int	z_scale(int key, fdf *data)
{
	if (key == Z_UP)
		data->z_scale += 0.1;
	if (key == Z_DOWN)
		data->z_scale -= 0.1;
	return (0);
}

int main(int argc, char **argv)
{
	fdf *data;
	
	if (argc != 2 || file_check(argv[1]) == 1)
		return (0);
	data = malloc(sizeof(fdf));
	ft_read_file(argv[1], data);
	first_init(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1800, 1000, "FDF");
	draw(data);
	print_menu(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	free (data);
	return (0);
}


void	ft_free_data_struct(fdf *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
	{
		free(data->z_matrix[i]);
		i++; 
	}
	free(data->z_matrix);
	free(data);
}
