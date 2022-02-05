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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int		num;
    int     index;    
	struct s_list	*next;
}	t_list;

t_list    *ft_get_last(t_list *head);
void    ft_add_node_back(t_list **stack, t_list *new_node);
t_list    *ft_create_node(int number);
void    ft_init_stack(t_list **stack, int argc, char **argv);

#endif