/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:10:48 by chorse            #+#    #+#             */
/*   Updated: 2021/12/02 16:56:05 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_ost(char *ost)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (ost[i] != '\n' && ost[i])
		i++;
	if (!ost[i])
	{
		free(ost);
		ost = NULL;
		return (NULL);
	}
	line = malloc((ft_strlen(&ost[i + 1]) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strcpy(line, &ost[i + 1], ft_strlen(&ost[i]));
	line[ft_strlen(&ost[i + 1])] = '\0';
	free(ost);
	ost = NULL;
	return (line);
}

char	*ft_line(char *ost)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (ost[i])
	{
		while (ost[i] != '\n' && ost[i])
			i++;
		i++;
		line = malloc((i + 1) * sizeof(char));
		if (!line)
			return (NULL);
		ft_strcpy(line, ost, i);
		line[i] = '\0';
	}	
	return (line);
}

char	*ft_read(int fd, char *ost)
{
	char	*buf;
	int		n_read;
	// char	ch;
	// if (read(fd, &ch, 0) < 0)
	// 	return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	n_read = 1;
	while (n_read > 0)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		buf[n_read] = '\0';
		if (n_read < 0)
		{
			free(buf);
			return (NULL);
		}
		if (n_read == 0)
			break ;
		ost = ft_strjoin(ost, buf);
		if (!ost)
		{
			free(buf);
			return (NULL);
		}
		if (ft_strchr(ost, '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (ost);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*ost;
	// char *tmp;

	if(!ost)
		ost = NULL;
	res = NULL;
	if ((fd < 0 ) || (BUFFER_SIZE <= 0))
		return (NULL);
	ost = ft_read(fd, ost);
	if (ost)
	{
		res = ft_line(ost);
		// tmp = ost;
		ost = ft_ost(ost);
		// free(tmp);
	}
	return (res);
}

// int main()
// {
//     int fd;
    
//     fd = open("text.txt", O_RDONLY);
//     printf("res(1) = %s\n", get_next_line(fd));
// 	printf("res(2) = %s\n", get_next_line(fd));
// 	printf("res(3) = %s\n", get_next_line(fd));
// }