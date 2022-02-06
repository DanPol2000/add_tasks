/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:34:26 by chorse            #+#    #+#             */
/*   Updated: 2022/02/05 13:59:08 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;	

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			exit(0);
	}
	else
		i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]))
			write(1, "Error", 7);
		if (ft_is_repeat(tmp, argv, i))
			write(1, "Error", 7);
		if (tmp < INT32_MIN || tmp > INT32_MAX)
			write(1, "Error", 7);
		i++;
	}
	if (argc == 2)
		ft_freee(argv);
}


