/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:39:18 by chorse            #+#    #+#             */
/*   Updated: 2021/11/23 17:41:55 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_end()
{
	*res = ft_strdup(ost);
	*res = ft_strjoin(*res, "\n");
	while (ost[i] != '\0')
		i++;
	line = malloc((i) * sizeof(char));
    i = 0;
    while (ost[i] != '\n' && ost[i] != '\0')
    {
		line[i] = ost[i];
		i++;
    }
    return (line);
}



char *ft_line(char *ost)
{
    char *line;
    int  i;

    i = 0;
    if (!ost[i])
        return (NULL);
	if (ft_strchr(ost, '\n'))
	{
		while (ost[i] != '\n')
			i++;
		line = malloc((i + 2) * sizeof(char*));
	}
	else
	{
		while (ost[i] != '\0')
			i++;
		line = malloc((i) * sizeof(char));
	}
    i = 0;
    while (ost[i] != '\n' && ost[i] != '\0')
    {
		line[i] = ost[i];
		i++;
    }
    return (line);
}

char *ft_ost(char *ost, char **res, int n_read)
{
    int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (ft_strchr(ost, '\n'))
	{
		*res = ft_line(ost);
		while (ost[i] != '\0' && ost[i] != '\n')
			i++;
		line = ft_calloc((ft_strlen(ost) - i + 1), sizeof(char));
		i++;
		while (ost[i])
			line[j++] = ost[i++];
	}
	else if ((n_read = 0) && ost)
	{
		printf("ELSIFFF\n");
		*res = ft_strdup(ost);
		*res = ft_strjoin(*res, "\n");
		//f
		return (NULL);
	}
	else
	{
		printf("OST_HERE=%s\n", ost);
		printf("ELSEEE\n");
		while (ost[i] != '\0' && ost[i] != '\n')
			i++;
		line = ft_calloc((ft_strlen(ost) - i + 1), sizeof(char));
		i = 0;
		while (ost[i])
			line[j++] = ost[i++];
		printf("LINE=%s\n", line);
	}
	if (ost)
		free(ost);
	return (line);	
}


char *ft_read(int fd, char *ost, char **res, int n_read)
{
	char  buf[BUFFER_SIZE + 1];

    n_read = read(fd, &buf, BUFFER_SIZE);
	buf[n_read] = '\0';
	printf("BUFF=%s\n", buf);
    if (n_read > 0)
	{
		printf("SSSSS\n");
		if (ost)
			ost = ft_strjoin(ost, buf);
		else
			ost = ft_strdup(buf);
	}
	else if (n_read == 0 && ost)
	{
		printf("ElseSSSSeS\n");
		ost = ft_ost(ost, res, n_read);
		//f(ost);
		return (NULL);
	}
	else
    {
		printf("Aefe\n");
		free(buf);
		return (NULL);
	}
	//f(buff);
	return (ost);
}


char *get_next_line(int fd)
{
    char  *res;
    static char *ost;
	int		n_read;
	
	n_read = 0;
	res = NULL;
    if ((fd < 0 ) || (BUFFER_SIZE <= 0))
		return (NULL);
	ost = ft_read(fd, ost, &res, n_read);
	printf("OST=%s\n", ost);
	if (ost)
    	ost = ft_ost(ost, &res, n_read);
	printf("OST_LAST=%s\n", ost);
    return (res);
}


int main()
{
    int fd;
    
    fd = open("text.txt", O_RDONLY);
    printf("res(1) = %s\n", get_next_line(fd));
	printf("res(2) = %s\n", get_next_line(fd));
	printf("res(3) = %s\n", get_next_line(fd));
	printf("res(4) = %s\n", get_next_line(fd));
}