/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:08:14 by chorse            #+#    #+#             */
/*   Updated: 2021/12/13 17:46:16 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_forx(long long int num, int base, int low)
{	
	long long int e;
	
	e = num;
	if (num < 0)
	{
		e = 4294967296 + num;
		printf("ee = %lld\n", e);}
	return (ft_itoa(e, base, low));
}
