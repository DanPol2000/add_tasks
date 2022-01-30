/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:34:26 by chorse            #+#    #+#             */
/*   Updated: 2022/01/30 14:50:49 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_fill_list(int argc, char **input)
{
	int		i;
	t_list	*head;
	t_list	*temp;

	i = 0;
	head = NULL;
	while (i < argc)
	{
		temp = ft_lstnew(ft_atoi(input[i]));
		if (temp == NULL)
		{
			ft_lstfree(&head);
			break ;
		}
		ft_lst_add_back(&head, temp);
		i++;
	}
	ft_free_array(input);
	return (head);
}

void	ft_lst_add_back(t_list **head, t_list *new)
{
	t_list	*current;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}