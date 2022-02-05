/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:13:04 by chorse            #+#    #+#             */
/*   Updated: 2022/02/05 17:40:54 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_pb(t_list **stack_from, t_list **stack_into);
void	ft_add_list_front(t_list **stack, t_list *new_list);

void	ft_pb(t_list **stack_from, t_list **stack_into)
{
	t_list	*tmp;

	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	ft_add_list_front(stack_into, tmp);
	write(1, "pb\n", 4);
}

void	ft_ra(t_list **stack)
{
	t_list	*tail;
	t_list	*head;

	tail = ft_get_last(*stack);
	head = *stack;
	*stack = (*stack)->next;
	tail->next = head;
	head->next = NULL;
	write(1, "ra\n", 4);;
}

void	ft_add_list_front(t_list **stack, t_list *new_list)
{
	if (!new_list)
		return ;
	new_list -> next = *stack;
	*stack = new_list;
}

void	ft_sort_five(t_list **s_a, t_list **s_b)
{
	int		tmp;
	int		snd;
	t_list	*head;
	int		cnt;
	int		last;
	int 	i;
	
	tmp = -1;
	snd = -1;
	cnt = 1;
	last = 1;
	i = 0;
	head = *s_a;
	(*s_a) = head;
	tmp = (*s_a)->num;	printf("TMP = %d\n", tmp);
	while ((*s_a))
	{
		if ((*s_a)->num < tmp || ((*s_a)->num < snd && (*s_a)->num > tmp))
		{
			snd = tmp;
			tmp = (*s_a)->num;
			cnt++;
		}	
		(*s_a) = (*s_a)->next;
	}
	(*s_a) = head;

	printf("cnt = %d\n", cnt);
	printf("SND = %d\n", snd);
	/*while (i < 5)
	{
		if ((cnt == 0 )|| (last == 0))
			ft_pb(s_a, s_b);
		else
		{
			cnt--;
			last--;
			i++;
		}	
	}
	*/
	// snd = (*s_b)->num;
	// printf("FINISH = %d\n", snd);
}

int main(int argc, char **argv)
{
	t_list **stack_a;
	t_list **stack_b;
	
	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_fill_stack(stack_a, argc, argv);
	ft_sort_five(stack_a, stack_b);
}
