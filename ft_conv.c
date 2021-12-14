/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:17:58 by chorse            #+#    #+#             */
/*   Updated: 2021/12/14 16:07:25 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv(int c, va_list args)
{
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	if (c == 'p')
		return (ft_putstr_fd("0x", 1)
			+ ft_itoa(va_arg(args, unsigned long long int), 16, 32));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (c == 'u')
		return (ft_itoa(va_arg(args, unsigned int), 10, 0));
	if (c == 'X')
		return (ft_itoa(va_arg(args, unsigned int), 16, 0));
	if (c == 'x')
		return (ft_itoa(va_arg(args, unsigned int), 16, 32));
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
