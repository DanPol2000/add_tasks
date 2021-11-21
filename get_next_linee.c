#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>


int ft_strrlen(char *buf)
{
    int i;

    i = 0;
    while (buf[i] && buf[i] != '\n')
		i++;
    i = 0;
    while (buf[i] != '\n' || buf[i] != '\0')
        i++;
    return (i);
}

char *ft_line(char *buf)
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
		line[i++] = '\n';
    return (line);
}

char *ft_ost(char *buffer)
{
    int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
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
    int j;

    j = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    while (n_read > 0)
    {
        n_read = read(fd, &buf, BUFFER_SIZE);
        if (n_read == -1)
		    return (NULL);
        buf[n_read] = '\0';
    }
    if (n_read < 0)
        return (0);
    res = ft_line(buf);
    while (buf[j] != '\n')
        j++;
    ost = ft_substr(buf, j, ft_strrlen(buf));
    return (res);
}


int main()
{
    int fd;
    
    fd = open("text.txt", O_RDONLY);
    printf("res = %s", get_next_line(fd));
}