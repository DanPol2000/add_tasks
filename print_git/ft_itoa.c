/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:26:41 by chorse            #+#    #+#             */
/*   Updated: 2021/12/15 13:57:43 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long int n, int base)
{
	unsigned long int	cnt;

	cnt = 0;
	if (n == 0)
	{
		cnt++;
		return (cnt);
	}
	while (n > 0)
	{
		n = n / base;
		cnt++;
	}
	return (cnt);
}

static char	ft_zero(unsigned long int x, char *str)
{
	if (x == 0)
	{
		str[0] = '0';
		return (*str);
	}
	return (0);
}

int	ft_itoa(unsigned long int n, int base, int low)
{
	char				*str;
	unsigned long int	x;
	int					i;

	x = n;
	i = ft_count(n, base);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	ft_zero(x, str);
	while (x > 0)
	{
		if (x % base >= 10)
			str[i] = x % base + 7 + low + '0';
		else
			str[i] = x % base + '0';
		x = x / base;
		i--;
	}
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}
