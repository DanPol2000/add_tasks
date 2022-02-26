/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:08:05 by chorse            #+#    #+#             */
/*   Updated: 2022/02/26 15:35:36 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "get_next_line/get_next_line.h"
#include "stdio.h"
#include <fcntl.h>
#include <math.h>
#include <mlx.h>

# define WIDTH			1000
# define HEIGHT			1080

# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define ESC			53
# define ZOOM_UP		24
# define ZOOM_DOWN		27
# define ANGLE_COS_DOWN	1
# define ANGLE_COS_UP	0
# define ANGLE_SIN_DOWN	2
# define ANGLE_SIN_UP	3
# define Z_UP			13
# define Z_DOWN			12
# define ISO_ON			18
# define ISO_OFF		19
# define RESET			48

typedef struct s_z_color
{
	int		z;
	int		color;
}	t_z_color;


typedef struct
{
	int width;
	int height;
	int **z_matrix;
	int		zoom;
	int		color;
	double	angle_cos;
	double	angle_sin;
	double	z_scale;
	int		flag;
	int		shift_x;
	int		shift_y;

	int		scr_x;
	int		scr_y;
	
	void *mlx_ptr;
	void *win_ptr;
}		fdf;

void	freeh(char **arr);
int		ft_get_height(char *file);
int		ft_get_width(char *file);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char	*str);
void	ft_create_matrix(char *file_name, fdf *data);
void	ft_read_file(char *file_name, fdf *data);
static int	ft_generate_matrix(fdf *data, char **numbers, int i);
int	ft_get_int(char *a);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
float	ft_mod(float a);
float	ft_max(float a, float b);
void	first_init(fdf *data);
void	draw(fdf *data);
void	ft_make_zoom(float x, float y, float x1, float y1, fdf *data);

#endif