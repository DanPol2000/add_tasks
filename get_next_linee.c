/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:15:50 by chorse            #+#    #+#             */
/*   Updated: 2021/11/22 21:11:57 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_line(char *buf, char **res)
{
    char *line;
    int  i;

    i = 0;
    if (!buf[i])
        return (NULL);
    while (buf[i] != '\0' && buf[i] != '\n')
		i++;
    line = malloc((i + 2) * sizeof(char));
    i = 0;
    while (buf[i] != '\n')
    {
		line[i] = buf[i];
		i++;
    }
    if (buf[i] && buf[i] == '\n')
	{
		*res = ft_strdup(line);
		*res = ft_strjoin(*res, "\n");
	}
    return (line);
}

char *ft_ost(char *buffer, char *ost, char **res)
{
    int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	//zdec i frree
	while (ost[i] != '\0' && ost[i] != '\n')
		i++;
	printf("CNHJR\n");
    if (ost[i] && ost[i] == '\n')
	{
		*res = ft_strdup(line);
		*res = ft_strjoin(*res, "\n");
		return (ost);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	/*if (!buffer[i])
	{
		free(buffer);
		return (ost);
	}
	*/
    while (buffer[i])
		line[j++] = buffer[i++];
	//zdec i frree
	return (line);
}

char *get_next_line(int fd)
{
    char  buf[BUFFER_SIZE + 1];
    char  *res;
    static char *ost;
    int   n_read;

	res = NULL;
    if ((fd < 0 ) || (BUFFER_SIZE <= 0))
		return (NULL);
    while (!res)
    {
		printf("OST_previous = %s\n", ost);
        n_read = read(fd, &buf, BUFFER_SIZE);
		buf[n_read] = '\0';
        if (n_read < 0)
            return (0);
		else if (n_read == 0 && ft_strlen(ost) > 0)
			ost = ft_ost(buf, ost, &res);
		else
		{
			if (ost)
				ost = ft_strjoin(ost, buf);
			else
			{
				printf("Nachalo\n");
				ost = ft_line(buf, &res);
			}
		}
		printf("OST_Last = %s\n", ost);
		printf("RESULT = %s\n", res);
    	ost = ft_ost(buf, ost, &res);
		printf("OST_FInal = %s\n", ost);
	} 	
	printf("res = %s", res);
    return (res);
}


int main()
{
    int fd;
    
    fd = open("text.txt", O_RDONLY);
    printf("res(1) = %s", get_next_line(fd));
	printf("res(2) = %s", get_next_line(fd));
}