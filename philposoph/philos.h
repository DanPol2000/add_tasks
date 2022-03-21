/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:39:24 by chorse            #+#    #+#             */
/*   Updated: 2022/03/21 16:59:31 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos
{
	long		name;
	long		sleep;
	long	eating;
	long	time_life;
	long		amount;
	long 	time;
	long	left_f;
	long		right_f;
	// pthread_mutex_t	entry_point;
}	t_phil;

typedef	struct	s_base
{
	t_phil	*philos;
	int		count;
}	t_base;

void	parser(t_base *phil, char **argv);
long	ft_atoi(const char *str);
int		ft_strlen(const char *str);
void threads(t_base *data);

#endif