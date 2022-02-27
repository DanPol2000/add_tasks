/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:00:31 by chorse            #+#    #+#             */
/*   Updated: 2022/02/27 16:16:35 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(fdf *data)
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

void	first_init(fdf *data)
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
