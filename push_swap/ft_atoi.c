/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:00:12 by chorse            #+#    #+#             */
/*   Updated: 2022/02/13 16:05:34 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_issp(int c)
{
	if (c == '\f' || c == '\n' || c == '\t' || c == '\r'
		|| c == '\v' || c == ' ')
		return (c);
	return (0);
}

static int	ft_plus(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && (s[i + 1] == '+' || s[i + 1] == '-'))
		return (1);
	return (0);
}

long	ft_atoi(const char	*str)
{
	int			min;
	long int	numb;

	min = 1;
	numb = 0;
	while (ft_issp(*str))
		str++;
	if (ft_plus((char *)str))
		return (0);
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		min *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		numb = (numb * 10) + *str++ - '0';
	return (numb * min);
}
