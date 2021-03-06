/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:38:14 by chorse            #+#    #+#             */
/*   Updated: 2022/03/21 17:00:53 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int mails = 0;
pthread_mutex_t	entry_point;

void *live(void *id)
{
	t_phil *philos;
	long i;
	struct timeval	tv;
	long time;
	
	gettimeofday(&tv, NULL);
	printf("%ld\n", time);
	i = 0;
	while ((long *)i < &philos->time_life)
	{
		pthread_mutex_lock(&entry_point);
		i++;
		mails++;
		pthread_mutex_unlock(&entry_point);
	}
	return (NULL);
}

void threads(t_base *data)
{
	pthread_t *threads;
	int i;

	threads = malloc(sizeof(pthread_t) * data->count);
	i = 0;
	while (i < data->count)
	{
		pthread_create(&threads[i], NULL, live, &data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->count)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}

void parser(t_base *base, char **argv)
{
	t_phil *philosophers;

	int i;

	philosophers = malloc(sizeof(t_phil) * base->count);
	if (!philosophers)
		return;
	i = 0;
	while (i < base->count)
	{
		philosophers[i].name = i + 1;
		philosophers[i].time_life = ft_atoi(argv[2]);
		philosophers[i].eating = ft_atoi(argv[3]);
		philosophers[i].sleep = ft_atoi(argv[4]);
		philosophers[i].left_f = (i + base->count) % base->count;
		philosophers[i].right_f = (i + base->count - 1) % base->count;
		i++;
	}
	// free(base->philos);
}

int main(int argc, char **argv)
{
	t_base *phil;
	// pthread_mutex_t	entry_point;
	pthread_mutex_init(&entry_point, NULL);
	phil = malloc(sizeof(t_base));
	phil->count = ft_atoi(argv[1]);
	parser(phil, argv);
	threads(phil);
	pthread_mutex_destroy(&entry_point);
	printf("MAILS = %d\n", mails);
	free(phil);
	return (0);
}
