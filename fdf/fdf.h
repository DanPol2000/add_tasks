/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:08:05 by chorse            #+#    #+#             */
/*   Updated: 2022/02/23 15:27:15 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "get_next_line/get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

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

#endif