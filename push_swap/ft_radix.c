/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:44:51 by chorse            #+#    #+#             */
/*   Updated: 2022/02/13 16:47:12 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big_sort(t_list **s_a, t_list **s_b)
{
	int		i;
	int		j;
	int		len;
	t_list	*ptr;

	j = 0;
	len = ft_lstsize(*s_a);
	ft_get_id(*s_a);
	while (ft_is_sorted_stack(s_a) != 1)
	{
		i = 0;
		while (i < len)
		{
			if (((*s_a)->index >> j & 1) == 0)
				ft_pb(s_a, s_b);
			else
				ft_ra(s_a);
			i++;
		}
		ptr = *s_b;
		while ((*s_b))
			ft_pa(s_b, s_a);
		j++;
	}
}

static void	ft_sort(int **tmp, int size)
{
	int	i;
	int	j;
	int	buff;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if ((*tmp)[j] > (*tmp)[j + 1])
			{
				buff = (*tmp)[j];
				(*tmp)[j] = (*tmp)[j + 1];
				(*tmp)[j + 1] = buff;
			}
			j++;
		}
		i++;
	}
}

static int	*ft_massive(t_list *list)
{
	int	*mass;
	int	i;

	mass = malloc(sizeof(int) * ft_lstsize(list));
	if (!mass)
		return (0);
	i = 0;
	while (list)
	{
		mass[i] = list->num;
		i++;
		list = list->next;
	}
	mass[i] = '\0';
	return (mass);
}

void	ft_get_id(t_list *list)
{
	int		*tmp;
	int		i;
	int		size;
	t_list	*ptr;

	ptr = list;
	size = ft_lstsize(list);
	tmp = ft_massive(list);
	ft_sort(&tmp, size);
	i = 0;
	list = ptr;
	while (ptr)
	{
		i = 0;
		while (tmp[i] != ptr->num)
			i++;
		ptr->index = i;
		ptr = ptr->next;
	}
	free(tmp);
}
