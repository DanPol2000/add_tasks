/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:29:45 by chorse            #+#    #+#             */
/*   Updated: 2021/10/17 14:16:03 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!s1)
		return (NULL);
	if (ft_strlen(s1) < start)
		len = 0;
	if (ft_strlen(s1) < len)
		len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		if (i >= start && y < len)
			s2[y++] = s1[i];
		i++;
	}
	s2[y] = '\0';
	return (s2);
}
