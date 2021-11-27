/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:26:15 by chorse            #+#    #+#             */
/*   Updated: 2021/11/27 18:17:50 by chorse           ###   ########.fr       */
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
		return (NULL);
	}
	line = malloc((ft_strlen(&ost[i + 1]) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strcpy(line, &ost[i + 1], ft_strlen(&ost[i]));
	line[ft_strlen(&ost[i + 1])] = '\0';
	free(ost);
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
		line = malloc((i) * sizeof(char));
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
	return (ost);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*ost;

	res = NULL;
	if ((fd < 0 ) || (BUFFER_SIZE <= 0))
		return (NULL);
	ost = ft_read(fd, ost);
	if (ost)
	{
		res = ft_line(ost);
		ost = ft_ost(ost);
	}
	return (res);
}

int main()
{
    int fd;
    
    fd = open("text.txt", O_RDONLY);
    printf("res(1) = %s\n", get_next_line(fd));
	printf("res(2) = %s\n", get_next_line(fd));
}
