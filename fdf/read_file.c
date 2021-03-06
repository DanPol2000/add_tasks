/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:27:43 by chorse            #+#    #+#             */
/*   Updated: 2022/03/06 18:50:31 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free (nums);
}

int	ft_read_file(char *file, t_fdf *data)
{
	int		i;

	i = 0;
	data->height = ft_get_height(file);
	data->width = ft_get_width(file);
	if (data->width < 0 || data->height < 0)
		exit (0);
	data->z_matrix = malloc(sizeof(int *) * (data->height + 1));
	if (!data->z_matrix)
		return (1);
	while (i <= data->height)
	{
		data->z_matrix[i++] = malloc(sizeof(int) * (data->width + 1));
		if (!data->z_matrix[i])
		{
			free(data->z_matrix);
			return (1);
		}
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
	while (arr[width])
	{
		free(arr[width]);
		width++;
	}
	free(arr[width]);
	free(arr);
	return (width);
}
