/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:48:54 by marvin            #+#    #+#             */
/*   Updated: 2021/10/28 11:48:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_line(char *buf, char *res)
{
    char *line;
    int  i;

    i = 0;
    if (!buf[i])
        return (NULL);
    while (buf[i] && buf[i] != '\n')
		i++;
    line = ft_calloc(i + 2, sizeof(char));
    i = 0;
    while (buf[i] != '\n' || buf[i] != '\0')
    {
        line[i] = buf[i];
        i++;
    }
    if (buf[i] && buf[i] == '\n')
	{
		line[i++] = '\n';
		res = ft_strdup(line);
	}
    return (line);
}

char *ft_ost(char *buffer, char *ost)
{
    int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	if (!buffer[i])
	{
		free(buffer);
		return (ost);
	}
    while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char *get_next_line(int fd)
{
    char  buf[BUFFER_SIZE + 1];
    char  *res;
    static char *ost;
    int   n_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    while (!res)
    {
        n_read = read(fd, &buf, BUFFER_SIZE);
		buf[n_read] = '\0';
        if (n_read < 0)
            return (0);
		else if (n_read == 0 && ft_strlen(ost) > 0)
		{
			res = ft_strdup(ost);
			free(ost);
		}
		else
		{
			if (ost)
				ost = ft_strjoin(ost, buf);
			ost = ft_line(buf, res);
		}
	}
    ost = ft_ost(buf, ost);
    return (res);
}


int main()
{
    int fd;
    
    fd = open("text.txt", O_RDONLY);
    printf("res = %s", get_next_line(fd));
}