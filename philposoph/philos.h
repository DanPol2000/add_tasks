/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:39:24 by chorse            #+#    #+#             */
/*   Updated: 2022/03/21 12:44:24 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philos
{
	int		name;
	int		sleep;
	int		eating;
	int		time_life;
	int		amount;
	int 	time;
	int		left_f;
	int		right_f;
	pthread_mutex_t 
}	t_phil;

typedef	struct	s_base
{
	t_phil	*philos;
	int		count;
}	t_base;

void	parser(t_base *phil, char **argv);
long	ft_atoi(const char *str);
int		ft_strlen(const char *str);

#endif