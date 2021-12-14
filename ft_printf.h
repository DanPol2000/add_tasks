/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:22:43 by chorse            #+#    #+#             */
/*   Updated: 2021/12/14 16:41:01 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *string, int c);
int		ft_conv(int c, va_list args);
void	ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_itoa(unsigned long int n, int base, int low);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);

#endif