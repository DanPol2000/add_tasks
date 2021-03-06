/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:32:52 by chorse            #+#    #+#             */
/*   Updated: 2021/10/19 17:38:08 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
