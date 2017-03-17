/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:56:48 by wliu              #+#    #+#             */
/*   Updated: 2016/12/12 11:01:12 by sijang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*create_list(char *str)
{
	t_lst	*begin;
	t_lst	*new;
	char	c;

	begin = NULL;
	c = 'A';
	while (*str)
	{
		new = valid_tetrim(str);
		if (new == NULL)
		{
			free_tetrim(begin);
			return (NULL);
		}
		begin = add_tetrim(begin, new, c);
		str += 19;
		if (str == 0 || *str == '\0')
			break ;
		str += 2;
		c++;
	}
	return (begin);
}

t_lst	*add_tetrim(t_lst *begin, t_lst *new_tetrim, char c)
{
	t_lst	*tmp;

	new_tetrim->letter = c;
	if (begin == NULL)
		return (new_tetrim);
	else
	{
		tmp = begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_tetrim;
		return (begin);
	}
}
