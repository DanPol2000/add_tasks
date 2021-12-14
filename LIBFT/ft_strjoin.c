/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:28:09 by chorse            #+#    #+#             */
/*   Updated: 2021/10/15 14:07:05 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s3;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = malloc(sizeof(*s3) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (*s1 != '\0')
		s3[i++] = *s1++;
	while (*s2 != '\0')
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}
