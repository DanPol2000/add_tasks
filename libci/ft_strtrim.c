/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:29:23 by chorse            #+#    #+#             */
/*   Updated: 2021/10/19 16:41:11 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char const *set, char s)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_check(char const *s1, char const *set)
{
	while (*s1)
	{
		if (!ft_set(set, *s1))
			return (0);
		s1++;
	}
	return (1);
}

static int	ft_i(char const *s1, int i, char const *set)
{
	while (s1[i] != '\0')
		i++;
	i--;
	while ((*s1 && ft_set(set, s1[i])))
		i--;
	return (i);
}

static char	*ft_last(char *s2)
{
	s2 = malloc(1);
	if (!s2)
		return (NULL);
	s2[0] = '\0';
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!s1 || !set)
		return (NULL);
	if (ft_check(s1, set))
	{
		s2 = malloc(1);
		if (!s2)
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	y = ft_i(s1, i, set);
	while (*s1 && ft_set(set, s1[i]))
		i++;
	s2 = ft_substr((char *)s1, i, ((y - i) + 1));
	if (!s2)
		ft_last(s2);
	return (s2);
}
