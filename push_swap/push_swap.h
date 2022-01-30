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
	int				num;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *num);
t_list	ft_begin(int argc, char **argv);
char	**ft_split(char const *s, char c);
int	check_sorted(t_list *s_a);
void	ft_sort_three(t_list **s_a);
void	ft_check_args(int argc, char **argv);
int	ft_atoi(const char	*str);


#endif