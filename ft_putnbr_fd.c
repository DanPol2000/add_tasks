/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:27:38 by chorse            #+#    #+#             */
/*   Updated: 2021/12/12 20:06:06 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbr;
	int cnt;
	int nd;

	cnt = 0;
	nd = nb;
	if (nb == 0)
		cnt = 1;
	while (nd)
	{
		nd = nd / 10;
		cnt++;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		cnt++;
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
	return (cnt);
}

