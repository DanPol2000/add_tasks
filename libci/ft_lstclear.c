/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:13:03 by chorse            #+#    #+#             */
/*   Updated: 2021/10/20 19:59:31 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*s;

	s = *lst;
	while (s)
	{
		tmp = s->next;
		if (del)
			del(s->content);
		free(s);
		s = tmp;
	}
	*lst = NULL;
}
