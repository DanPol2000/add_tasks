/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:40:26 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/27 21:15:52 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_zero(int	**arr, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		*arr[i] = 0;
		i++;
	}
}

void	philo_fill(t_philo *state, t_data *data)
{
	int	i;
	struct timeval	tv;

	i = 0;
	while (i < data->number)
		pthread_mutex_init(&data->forks[i++], NULL);
	i = 0;
	gettimeofday(&tv, NULL);
	while (i < data->number)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		state[i].hungry = 0;
		state[i].eating = 0;
		state[i].thinking = 0;
		state[i].time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		state[i].time_die = data->time_die;
		state[i].time_sleep = data->time_sleep;
		state[i].time_eat = data->time_eat;
		state[i].left = (i + data->number) % data->number;
		state[i].right = (i + 1) % data->number;
		state[i].num = i;
		state[i].last_after_eat = state[i].time_start;
		state[i].number_of_times = data->number_of_times;
		state[i].left_fork_m = &data->forks[state[i].left];
		state[i].right_fork_m = &data->forks[state[i].right];
		state[i].last_time_eat = state[i].time_start;
		i++;
	}
}

void	philo_states(t_data *data)
{
	data->state = malloc(sizeof(t_philo) * data->number + 1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number + 1);
	data->array_number_of_times = malloc(sizeof(int) * data->number + 1);
	philo_fill(data->state, data);
}

void	parse(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	data->number_of_times = -1;
	while (i < argc)
	{
		if (i == 1)
			data->number = ft_atoi(argv[i]);
		if (i == 2)
			data->time_die = ft_atoi(argv[i]);
		if (i == 3)
			data->time_eat = ft_atoi(argv[i]);
		if (i == 4)
			data->time_sleep = ft_atoi(argv[i]);
		if (i == 5)
			data->number_of_times = ft_atoi(argv[i]);
		i++;
	}
	philo_states(data);
}

void	take_forks(t_philo *philo)
{
	int	local;
	struct timeval	tv;

	if (philo->left == philo->right)
		usleep(philo->time_die);
	pthread_mutex_lock(philo->right_fork_m);
	gettimeofday(&tv, NULL);
	philo->time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	ft_custom_printf(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork_m);
	gettimeofday(&tv, NULL);
	philo->time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	ft_custom_printf(philo, "has taken a fork");
	local = philo->left;
}

void	ft_custom_printf(t_philo *philo, char *s)
{
	printf("%lld %d %s\n", philo->time - philo->time_start, philo->num, s);
}

void	eating(t_philo *philo)
{
	struct timeval	tv;
	
	philo->last_after_eat = philo->last_time_eat;
	ft_custom_printf(philo, "is eating\n");
	usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(philo->left_fork_m);
	pthread_mutex_unlock(philo->right_fork_m);
	gettimeofday(&tv, NULL);
	philo->last_time_eat = tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void	thinking(t_philo *philo)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	philo->time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	ft_custom_printf(philo, "is thinking\n");
}

void	sleeping(t_philo *philo)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	philo->time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	ft_custom_printf(philo, "is sleeping\n");
	usleep(philo->time_sleep * 1000);
}

int	time_to_ms(long first, long second)
{
	long long	tmp;
	
	tmp = second - first;
	printf("First = %ld\n", first);
	printf("Second = %ld\n", second);
	printf("TMP = %lld\n", tmp);
	// printf("first.tv_usec->%d\n", first.tv_usec);
	return (tmp);
}

void	*func(void *arg)
{
	t_philo	*args;
	struct timeval	tv;

	args = arg;
	if (args->num % 2 == 0)
		usleep(500);
	// printf("args->time_die->%d\n", args->time_die);
	gettimeofday(&tv, NULL);
	while (time_to_ms(args->last_after_eat, args->last_time_eat) < args->time_die)
	{
		take_forks(args);
		// printf("NUM = %d\n", args->num);
		// printf("last_after_eat = %lld\n", args->last_after_eat - args->time_start);
		// printf("last_time_eat = %lld\n", args->last_time_eat - args->time_start);
		eating(args);
		sleeping(args);
		thinking(args);
	}
	gettimeofday(&tv, NULL);
	printf("TV = %lld\n", (tv.tv_sec * 1000 + tv.tv_usec / 1000) - args->time_start);
	printf("Philosoph %d is dead :(\n", args->num);
	exit (0);
	// printf("%d\n", args->time_die);
	return (NULL);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data			*data;
	int				i;
	

	i = 0;
	data = malloc(sizeof(t_data));
	parse(argc, argv, data);

	while (i < data->number)
	{
		pthread_create(&data->state[i].thread, NULL, func, (void *)(&data->state[i]));
		i++;
	}
	i = 0;
	while (i < data->number)
	{
		pthread_join(data->state[i].thread, NULL);
		i++;
	}
	// printf("numbers of philo = %d\n", data->number);
	// printf("t_die of philo = %d\n", data->time_die);
	// printf("t_eat of philo = %d\n", data->time_eat);
	// printf("t_sleep of philo = %d\n", data->time_sleep);
	// printf("number_of_times_each_philosopher_must_eat = %d\n", data->number_of_times);
	// printf("forks: = %d\n", data->forks); //CHECHS FOR VALUE
	destroy_mutex(data);
	// free(data->array_number_of_times);
	free(data->forks);
	free(data->state);
	free(data);
}
