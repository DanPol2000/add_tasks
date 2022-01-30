/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:58:28 by chorse            #+#    #+#             */
/*   Updated: 2022/01/29 12:59:47 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *num)
{
	t_list	*s;

	s = malloc(sizeof(*s));
	if (!s)
		return (NULL);
	s->num = num;
	s->next = NULL;
	return (s);
}