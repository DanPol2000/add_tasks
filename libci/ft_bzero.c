/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:25:51 by chorse            #+#    #+#             */
/*   Updated: 2021/10/15 12:42:47 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;
	int				c;

	i = 0;
	c = '\0';
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	s = str;
}
