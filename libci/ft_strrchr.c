/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:29:07 by chorse            #+#    #+#             */
/*   Updated: 2021/10/15 14:19:37 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*i;

	i = s;
	while (*s)
		s++;
	while (s >= i)
	{
		if (*s-- == (char)c)
			return ((char *)s + 1);
	}
	return (NULL);
}
