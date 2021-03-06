/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:58:17 by chorse            #+#    #+#             */
/*   Updated: 2022/02/13 16:16:36 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*s;
	int		i;

	i = 0;
	s = lst;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}
