/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:27:57 by chorse            #+#    #+#             */
/*   Updated: 2021/12/12 18:49:27 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *string, int c)
{
	while (*string)
	{
		if (*string == c || (c - *string == 256))
			return ((char *)string);
		string++;
	}
	if (c == '\0')
		return ((char *)string);
	return (NULL);
}
