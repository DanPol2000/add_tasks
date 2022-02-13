/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:13:04 by chorse            #+#    #+#             */
/*   Updated: 2022/02/13 16:49:43 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_list_front(t_list **stack, t_list *new_list)
{
	if (!new_list)
		return ;
	new_list -> next = *stack;
	*stack = new_list;
}

static void	f_out(t_list **s_a, int *tmp, int *snd)
{
	t_list	*head;

	head = (*s_a);
	*tmp = (*s_a)->num;
	(*s_a) = (*s_a)->next;
	while ((*s_a))
	{
		if ((*s_a)->num < *tmp)
		{
			*snd = *tmp;
			*tmp = (*s_a)->num;
		}
		(*s_a) = (*s_a)->next;
	}
	(*s_a) = head;
	while ((*s_a))
	{
		if ((*s_a)->num > *tmp && (*s_a)->num < *snd)
			*snd = (*s_a)->num;
		(*s_a) = (*s_a)->next;
	}
	(*s_a) = head;
}

void	ft_sort_five(t_list **s_a, t_list **s_b)
{
	int	tmp;
	int	snd;
	int	i;

	i = 0;
	f_out(s_a, &tmp, &snd);
	while (i < 5)
	{
		if ((*s_a)->num == tmp || (*s_a)->num == snd)
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
