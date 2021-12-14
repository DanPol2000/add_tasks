/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:12:59 by chorse            #+#    #+#             */
/*   Updated: 2021/10/19 17:23:22 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s;

	s = malloc(sizeof(*s));
	if (!s)
		return (NULL);
	s->content = content;
	s->next = NULL;
	return (s);
}
