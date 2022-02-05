/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:15:49 by chorse            #+#    #+#             */
/*   Updated: 2022/02/05 13:46:00 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list    *ft_get_last(t_list *head)
{
    if (!head)
        return (NULL);
    while (head -> next)
        head = head -> next;
    return (head);
}

void    ft_add_elem_back(t_list **stack, t_list *new_elem)
{
    t_list    *temp;

    if (!new_elem)
        return ;
    if (*stack)
    {
        temp = ft_get_last(*stack);
        temp -> next = new_elem;
    }
    else
        *stack = new_elem;
}

t_list    *ft_create_elem(int num)
{
    t_list    *new_elem;

    new_elem = (t_list *) malloc(sizeof(t_list));
    if (!new_elem)
        return (NULL);
    new_elem -> num = num;
    new_elem -> next = NULL;
    return (new_elem);
}

void    ft_fill_stack(t_list **stack, int argc, char **argv)
{
    t_list    *new;
    int        i;

    i = 0;
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
    else
        i = 1;
    while (argv[i])
    {
        new = ft_create_elem(ft_atoi(argv[i]));
        ft_add_elem_back(stack, new);
        i++;
    }
	if (argc == 2)
		ft_freee(argv);
}

void	ft_freee(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}