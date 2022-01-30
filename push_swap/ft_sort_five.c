/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:56:41 by chorse            #+#    #+#             */
/*   Updated: 2022/01/29 16:48:54 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void ft_help(t_list **s_a)
{
	if (!check_sorted(s_a) && (*s_a)->num < (*s_a)->next->num)
		ft_sort_three(s_a);	
	(*s_a) = head;
	while (len != 3)
	{
		(*s_a)= (*s_a)->next;
		len++
	}
	if (!check_sorted(s_a) && (*s_a)->num > (*s_a)->next->num)
	{
		ft_ra(s_a);
		ft_ra(s_a);
	}
}

static void	ft_sa(t_list **s_a)
{
	int	tmp;

	tmp = 0;
	tmp = (*s_a)->num;
	(*s_a)->num = (*s_a)->next->num;
	(*s_a)->next->num = tmp;
	*s_a = (*s_a)->next;
	write (1, "sa\n", 3);
}

void	ft_sort_five(t_list **s_a)
{
	int		tmp;
	t_list	*head;
	int 	len;

	head = *s_a;
	len = 0;
	tmp = 0;
	ft_help(s_a, head, len);
	(*s_a) = head;
	if (!check_sorted(s_a))
		ft_sort_three(s_a);	
	while (len != 3)
	{
		(*s_a)= (*s_a)->next;
		len++;
	}
	if (!check_sorted(s_a))
		ft_sort_three(s_a);
}
