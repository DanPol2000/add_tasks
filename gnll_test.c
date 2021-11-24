#include "get_next_line.h"


char *ft_end(char *ost, char ***res)
{
    char *line;
    char *osT;
    int i;

    i = 0;
    while (ost[i] != '\n')
		i++;
	line = malloc((i) * sizeof(char));
    osT = malloc((ft_strlen(ost) - i + 1) * sizeof(char));
    while (ost[i] != '\n' && ost[i] != '\0')
    {
        line[i] = ost[i];
		i++;
    }
    line[i] = '\n';
    i = 0;
    while (ost[i] != '\n' && ost[i] != '\0')
    {
		line[i] = ost[i];
		i++;
    }
    **res = ft_strdup(line);
    return (osT);
}

char *ft_line(char *ost)
{
    char *line;
    int  i;

    i = 0;
    if (!ost)
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

char *ft_ost(char *ost, char **res)
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


char *ft_read(int fd, char *ost, char **res)
{
	char  buf[BUFFER_SIZE + 1];
    int n_read;

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
		ost = ft_end(ost, &res);
		//f(ost);
		return (NULL);
	}
	else
    {
		printf("Aefe\n");
		return (NULL);
	}
	//f(buff);
	return (ost);
}


char *get_next_line(int fd)
{
    char  *res;
    static char *ost;

	res = NULL;
    if ((fd < 0 ) || (BUFFER_SIZE <= 0))
		return (NULL);
	ost = ft_read(fd, ost, &res);
	printf("OST=%s\n", ost);
	if (ost)
    	ost = ft_ost(ost, &res);
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