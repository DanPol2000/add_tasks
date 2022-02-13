/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:29:25 by chorse            #+#    #+#             */
/*   Updated: 2022/02/13 16:23:04 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_list **stack_from, t_list **stack_into)
{
	t_list	*tmp;

	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	ft_add_list_front(stack_into, tmp);
	write(1, "pb\n", 3);
}

void	ft_pa(t_list **stack_from, t_list **stack_into)
{
	t_list	*tmp;

	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	ft_add_list_front(stack_into, tmp);
	write(1, "pa\n", 3);
}

void	ft_ra(t_list **s_a)
{
	t_list	*tail;
	t_list	*head;

	tail = ft_get_last(*s_a);
	head = *s_a;
	*s_a = (*s_a)->next;
	tail->next = head;
	head->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_sb(t_list **s_b)
{
	t_list	*tmp;

	tmp = (*s_b)->next;
	(*s_b)->next = tmp -> next;
	tmp -> next = *s_b;
	*s_b = tmp;
	write(1, "sb\n", 3);
}
