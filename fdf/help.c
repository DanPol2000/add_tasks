/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:44:52 by chorse            #+#    #+#             */
/*   Updated: 2022/03/05 18:44:54 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	file_check(char *file_name)
{
	int	i;
	int	size;

	size = ft_strlen(file_name);
	i = size - 4;
	if (file_name[i++] != '.')
		return (1);
	if (file_name[i++] != 'f')
		return (1);
	if (file_name[i++] != 'd')
		return (1);
	if (file_name[i++] != 'f')
		return (1);
	return (0);
}