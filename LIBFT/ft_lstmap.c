/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:28:39 by chorse            #+#    #+#             */
/*   Updated: 2021/10/22 14:58:41 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clean(t_list *lst, void (*del)(void *), t_list *fst)
{
	ft_lstclear(&lst, del);
	ft_lstclear(&fst, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*fst;
	t_list	*sec;

	if (!lst || !f)
		return (NULL);
	sec = ft_lstnew(f(lst->content));
	if (!sec)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	fst = sec;
	lst = lst->next;
	while (lst)
	{
		sec = ft_lstnew(f(lst->content));
		if (!sec)
			ft_clean(lst, del, fst);
		lst = lst->next;
		ft_lstadd_back(&fst, sec);
	}
	return (fst);
}
