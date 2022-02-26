/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:27:43 by chorse            #+#    #+#             */
/*   Updated: 2022/02/26 13:21:04 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	fill_matrix(int *z_line, char *line)
{
	char **nums;
	int i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}


void	ft_read_file(char *file, fdf *data)
{
	int i;
	int fd;
	char *line;

	data->height = ft_get_height(file);
	data->width = ft_get_width(file);
	data->z_matrix = malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = malloc(sizeof(int) * (data->width + 1));
	fd = open(file, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;	
	}
	data->z_matrix[i] = NULL;
}

int	ft_get_height(char *file)
{
	char *line;
	int fd;
	int	height;
	
	fd = open(file, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = NULL;
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (height);
}

int ft_get_width(char *file)
{
	int fd;
	char *line;
	char **arr;
	int width;
	
	fd = open(file, O_RDONLY, 0);
	width = 0;
	line = get_next_line(fd);
	close(fd);
	arr = ft_split(line, ' ');
	while (arr[width])
		width++;
	freeh(arr);
	return (width);
}

void	freeh(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}