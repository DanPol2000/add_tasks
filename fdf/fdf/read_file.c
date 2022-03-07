/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:27:43 by chorse            #+#    #+#             */
/*   Updated: 2022/03/07 20:39:04 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> //DELETE

void	fill_matrix(t_dot *matrix, char *line, int y)
{
	char		**nums;
	char		**color;
	int			i;
	int			x;

	nums = ft_split(line, ' ');
	i = 0;
	x = 0;
	while (nums[i])
	{
		if (ft_strchr(nums[i], ',') == 0)
			get_color(&matrix[i], nums[i]);
		else
		{
			color = ft_split(nums[i], ',');
			matrix[i].z = ft_atoi(color[0]);
			matrix[i].color = hex_to_dec(color[1], x);
			ft_free(color);
		}
		matrix[i].y = y;
		matrix[i].x = i;
		i++;
	}
	ft_free(nums);
}

int	ft_read_file(char *file, t_fdf *data)
{
	int		i;

	i = 0;
	data->height = ft_get_height(file);
	data->width = ft_get_width(file);
	if (data->width < 0 || data->height < 0)
		exit (0);
	data->matrix = malloc(sizeof(t_dot *) * (data->height + 1));
	if (!data->matrix)
		return (1);
	while (i <= data->height)
	{
		data->matrix[i] = malloc(sizeof(t_dot) * (data->width + 1));
		if (!data->matrix[i])
		{
			free(data->matrix);
			return (1);
		}
		i++;
	}
	open_fill(file, data);
	return (0);
}

int	ft_get_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (height);
}

int	ft_get_width(char	*file)
{
	int		fd;
	char	*line;
	char	**arr;
	int		width;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
	width = 0;
	line = get_next_line(fd);
	close(fd);
	arr = ft_split(line, ' ');
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (arr[width])
		width++;
	ft_free(arr);
	return (width);
}
