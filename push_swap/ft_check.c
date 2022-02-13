/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:34:26 by chorse            #+#    #+#             */
/*   Updated: 2022/02/13 16:50:38 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	int		ind;

	i = 0;
	ind = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			exit(0);
	}
	else
		i = 1;
	ind = mistakes(argv, tmp, i);
	if (argc == 2)
		ft_freee(argv);
	if (ind == 1)
		return (1);
	return (0);
}

int	mistakes(char **argv, long long tmp, int i)
{
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]))
		{
			write(1, "Error", 5);
			return (1);
		}
		else if (ft_is_repeat(tmp, argv, i))
		{
			write(1, "Error", 5);
			return (1);
		}
		else if (tmp < -2147483648 || tmp > 2147483647)
		{
			write(1, "Error", 5);
			return (1);
		}
		i++;
	}
	return (0);
}
