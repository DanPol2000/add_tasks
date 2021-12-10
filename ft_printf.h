/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:43:19 by chorse            #+#    #+#             */
/*   Updated: 2021/12/10 16:15:35 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
#define	FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flag
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int precision; 
	int star;
}	t_flag;

void	ft_putchar_fd(char c, int fd);

#endif