/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:14:49 by chorse            #+#    #+#             */
/*   Updated: 2021/12/02 12:28:51 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *cache, char *buf)
{
	int		clen;
	int		blen;
	char	*str;

	clen = 0;
	blen = 0;
	if (cache == NULL)
	{
		cache = (char *)malloc(sizeof(char));
		if (!cache)
			return (NULL);
		cache[0] = '\0';
	}
	clen = ft_strlen(cache);
	blen = ft_strlen(buf);
	str = (char *)malloc(sizeof(char) * (clen + blen + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, cache, clen);
	ft_strcpy(&str[clen], buf, blen + 1);
	str[clen + blen + 1] = '\0';
	free(cache);
	cache = NULL;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return ((void *)0);
}

void	ft_strcpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while ((dest[i] || src[i]) && len--)
	{
		dest[i] = src[i];
		i++;
	}
}
