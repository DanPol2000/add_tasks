/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:27:43 by chorse            #+#    #+#             */
/*   Updated: 2021/12/12 18:41:19 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
		len++;
	}
	return (len);
}
