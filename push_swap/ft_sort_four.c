/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:16:01 by chorse            #+#    #+#             */
/*   Updated: 2022/02/13 16:53:00 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fo_out(t_list **s_a, int *tmp)
{
	t_list	*head;

	head = (*s_a);
	*tmp = (*s_a)->num;
	(*s_a) = (*s_a)->next;
	while ((*s_a))
	{
		if ((*s_a)->num < *tmp)
			*tmp = (*s_a)->num;
		(*s_a) = (*s_a)->next;
	}
	(*s_a) = head;
}

void	ft_sort_four(t_list **s_a, t_list **s_b)
{
	int	tmp;
	int	i;

	i = 0;
	fo_out(s_a, &tmp);
	while (i < 4)
	{
		if ((*s_a)->num == tmp)
			ft_pb(s_a, s_b);
		else
			ft_ra(s_a);
		i++;
	}
	ft_sort_three((s_a));
	if ((*s_b)->num < (*s_b)->next->num)
		ft_sb(s_b);
	while ((*s_b))
		ft_pa(s_b, s_a);
}
