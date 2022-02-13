/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:24:01 by chorse            #+#    #+#             */
/*   Updated: 2022/02/13 16:25:29 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		len;

	if (argc < 2)
		return (0);
	if (ft_check_args(argc, argv) == 1)
		return (0);
	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_fill_stack(stack_a, argc, argv);
	len = ft_lstsize(*stack_a);
	if (ft_is_sorted_stack(stack_a))
	{
		free_all(stack_a, stack_b);
		return (0);
	}
	last_check(stack_a, stack_b, len);
	free_all(stack_a, stack_b);
	return (0);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head ->next;
		free(tmp);
	}
	free(stack);
}

void	free_all(t_list **stack_a, t_list **stack_b)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}

void	last_check(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 3)
		ft_sort_three(stack_a);
	else if (len == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_big_sort(stack_a, stack_b);
}
