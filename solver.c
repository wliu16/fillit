/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sijang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:07:47 by sijang            #+#    #+#             */
/*   Updated: 2016/12/12 15:34:47 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fillmap(t_lst *cb, t_map *cm, int x, int y)
{
	int w;
	int h;

	w = 0;
	while (w < cb->hei)
	{
		h = 0;
		while (h < cb->wid)
		{
			if ((cm->map)[x + w][y + h] == '.' && (cb->shape)[w][h] == '#')
				(cm->map)[x + w][y + h] = cb->letter;
			h++;
		}
		w++;
	}
}

int			ck_promising(t_lst *cb, t_map *cm, int x, int y)
{
	int	h;
	int	w;

	w = 0;
	while (w < cb->hei)
	{
		h = 0;
		while (h < cb->wid)
		{
			if ((cm->map)[x + w][y + h] != '.' && (cb->shape)[w][h] == '#')
				return (FALSE);
			h++;
		}
		w++;
	}
	fillmap(cb, cm, x, y);
	return (TRUE);
}

void		mapback(t_lst *lb, t_map *mb, t_pos po)
{
	int w;
	int h;

	w = 0;
	while (w < lb->hei)
	{
		h = 0;
		while (h < lb->wid)
		{
			if ((mb->map)[po.x + w][po.y + h] == lb->letter)
				(mb->map)[po.x + w][po.y + h] = '.';
			h++;
		}
		w++;
	}
}

int			solver(t_lst *lst, t_map *cm, t_pos cur)
{
	if (lst == NULL)
		return (TRUE);
	cur.x = -1;
	while (++cur.x <= cm->size - lst->hei)
	{
		cur.y = -1;
		while (++cur.y <= cm->size - lst->wid)
		{
			if (ck_promising(lst, cm, cur.x, cur.y) == TRUE)
			{
				if (solver(lst->next, cm, cur) == TRUE)
					return (TRUE);
				else
					mapback(lst, cm, cur);
			}
		}
	}
	return (FALSE);
}

void		ft_fillit(t_lst *lst)
{
	t_pos	cur;
	t_map	*mp;
	int		nb;
	t_lst	*temp;

	cur.x = 0;
	cur.y = 0;
	nb = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		nb++;
	}//nb tetriminos
	mp = new_map(ft_fndsquare(nb * 4));//min size of map: sq(nb * 4)
	while (solver(lst, mp, cur) == FALSE)
	{
		nb = (mp->size) + 1;
		free_map(mp);
		mp = new_map(nb);
	}
	printmap(mp);
}
