/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:01:37 by chorse            #+#    #+#             */
/*   Updated: 2022/02/23 14:55:02 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
void	ft_strcpy(char *dest, char *src, int len);


#endif