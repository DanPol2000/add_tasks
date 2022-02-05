/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:24:01 by chorse            #+#    #+#             */
/*   Updated: 2022/02/05 14:23:53 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list **stack_a;
	t_list **stack_b;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_fill_stack(stack_a, argc, argv);
	if (ft_is_sorted_stack(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	ft_sort_three(stack_a);

}

void	ft_free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head ->next;
		free(temp);
	}
	free(stack);
}
