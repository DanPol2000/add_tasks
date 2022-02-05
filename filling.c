
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:05:42 by chorse            #+#    #+#             */
/*   Updated: 2022/01/30 13:38:20 by chorse           ###   ########.fr       */
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

void    ft_add_node_back(t_list **stack, t_list *new_node)
{
    t_list    *temp;

    if (!new_node)
        return ;
    if (*stack)
    {
        temp = ft_get_last(*stack);
        temp -> next = new_node;
    }
    else
        *stack = new_node;
}

t_list    *ft_create_node(int number)
{
    t_list    *new_node;

    new_node = (t_list *) malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node -> number = number;
    new_node -> index = -1;
    new_node -> next = NULL;
    return (new_node);
}

void    ft_init_stack(t_list **stack, int argc, char **argv)
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
        new = ft_create_node(ft_atoi(argv[i]));
        ft_add_node_back(stack, new);
        i++;
    }
	if (argc == 2)
		ft_free(argv);
}

void	ft_free(char **str)
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
