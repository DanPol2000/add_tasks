#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

// #define BUFFER_SIZE 42
int		ft_strlen(const char *s);
char	*ft_strjoin(char *cache, char *buf);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
void	ft_strcpy(char *dest, char *src, int len);

#endif