/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:41:17 by chorse            #+#    #+#             */
/*   Updated: 2021/12/10 16:56:48 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int cnt;
	t_flag flag;

    i = 0;
	cnt = 0;
	if (str == NULL)
		return (-1);
    va_start(args, str);
	ft_flag(&flag);
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
        if (str[i] == '%')
		{
			if (str[i + 1] == ' ');
			{
				ft_putchar_fd(str[i], 1);
				cnt++;
			}
			ft_parse(str, &flag, args, i);
		}
        i++;
    }
    va_end(args);
    return (cnt);
}

void	ft_flag(t_flag *flag)
{
	flag->type = 0;
	flag->width = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->precision = -1; 
	flag->star = 0;
}


int	ft_parse(const char *str, t_flag *flag, va_list args, int i)
{
	while (str[i])
	{
		if (str[i] == 0)
			flag->zero = 1;
		
	}
}