/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:00:35 by chorse            #+#    #+#             */
/*   Updated: 2022/02/13 16:52:48 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
}	t_list;

char		**ft_split(char const *s, char c);
void		ft_free_stack(t_list **stack);
long		ft_atoi(const char	*str);
void		ft_freee(char **str);
void		ft_fill_stack(t_list **stack, int argc, char **argv);
t_list		*ft_create_elem(int number);
void		ft_add_elem_back(t_list **stack, t_list *new_elem);
t_list		*ft_get_last(t_list *head);
int			ft_check_args(int argc, char **argv);
int			ft_is_repeat(int num, char **argv, int i);
int			ft_isnum(char *num);
int			ft_isdigit(int c);
int			ft_is_sorted_stack(t_list **stack);
void		ft_sort_three(t_list **s_a);
void		ft_ra(t_list **stack);
void		ft_pb(t_list **stack_from, t_list **stack_into);
void		ft_sort_five(t_list **s_a, t_list **s_b);
void		ft_add_list_front(t_list **stack, t_list *new_list);
void		ft_pa(t_list **stack_from, t_list **stack_into);
int			ft_lstsize(t_list *lst);
void		ft_sb(t_list **stack);
void		ft_big_sort(t_list **s_a, t_list **s_b);
void		ft_sort_four(t_list **s_a, t_list **s_b);
void		ft_get_id(t_list *lst);
int			mistakes(char **argv, long long tmp, int i);
void		last_check(t_list **stack_a, t_list **stack_b, int len);
void		free_all(t_list **stack_a, t_list **stack_b);

#endif