/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:03:09 by chorse            #+#    #+#             */
/*   Updated: 2022/02/23 15:26:07 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));
	ft_read_file(argv[1], data);
	
	int i;
	int j;
	
	i = 0;
	while(i < data->height)
	{
		j = 0;
		while(i < data->width)
		{
			printf("%d ", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
