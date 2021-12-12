/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:26:41 by chorse            #+#    #+#             */
/*   Updated: 2021/12/12 20:39:01 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	ft_check(long long int x, int base);
static int	ft_count(long long int n, int base)
{
	long long int	cnt;

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
		n = n / base;
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

int	ft_itoa(long long int n, int base, int low)
{
	char	*str;
	long long int	x;
	int		i;

	x = n;
	i = ft_count(n, base);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	ft_zero(x, str);
	if (x < 0)
	{
		str[0] = '-';
		x = x * -1;
	}
	while (x > 0)
	{
		if (ft_check(x, base))
			str[i] = x % base + 7 + low + '0'; 
		else
			str[i] = x % base + low + '0';	   		
		x = x / base;
		i--;
	}
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	ft_check(long long int x, int base)
{
	if (x % base >= 10)
		return (1);
	return (0);
}

int main()
{
	int d = -12345;
	int base = 16;
	int low = 0;
	int e;
	e = ft_forx(d, base, low);
	printf(" %d ", e);
	printf(" %x", d);
}