/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:35:32 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:35:34 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int cnt;

    i = 0;
	cnt = 0;
	if (str == NULL)
		return (-1);
    va_start(args, str);
    while (str[i])
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
		{
			if (str[i + 1] == ' ');
			{
				ft_putchar_fd(str[i], 1);
				cnt++;
			}
			cnt += ft_conv(str, &flag, args, i);
		}
        i++;
    }
    va_end(args);
    return (cnt);
}


int	ft_conv(int c, va_list args)
{
	if (c == 'c' || c == 's')
		return (ft_putstr_fd(args, 1));
	if (c == 'p')
		return (str = ft_itoa());
	if (c == 'd' || c == 'i')
		return (ft_putnmbr((va_arg(args, int)));
	if (c == 'u')
		return (ft_itoa(args));
	if (c == 'x' || c == 'X')
		return (ft_itoa(c, args));
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

