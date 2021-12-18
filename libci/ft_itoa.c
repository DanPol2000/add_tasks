/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:26:41 by chorse            #+#    #+#             */
/*   Updated: 2021/10/15 13:09:20 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		n = n * -1;
		cnt++;
	}
	if (n == 0)
	{
		cnt++;
		return (cnt);
	}
	while (n > 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

static char	ft_zero(long x, char *str)
{
	if (x == 0)
	{
		str[0] = '0';
		return (*str);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	x;
	int		i;

	x = n;
	i = ft_count(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	ft_zero(x, str);
	if (x < 0)
	{
		str[0] = '-';
		x = x * -1;
	}
	while (x > 0)
	{
		str[i] = x % 10 + '0';
		x = x / 10;
		i--;
	}
	return (str);
}
