/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:41:17 by chorse            #+#    #+#             */
/*   Updated: 2021/12/14 16:35:13 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		cnt;

	i = -1;
	cnt = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (str[++i])
	{
		while (str[i] != '%' && str[i])
		{
			ft_putchar_fd(str[i], 1);
			cnt++;
			i++;
		}
		if (!str[i])
			return (cnt);
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
			cnt += ft_conv(str[++i], args);
	}
	va_end(args);
	return (cnt);
}
