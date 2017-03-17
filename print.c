/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:09:44 by wliu              #+#    #+#             */
/*   Updated: 2016/12/12 15:37:01 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void		error(void)
{
	ft_putstr("error\n");
}

void		usage(void)
{
	ft_putstr("./fillit source_file\n");
}

void		printmap(t_map *map)
{
	int x;
	int y;

	x = 0;
	while (x < map->size)
	{
		y = 0;
		while (y < map->size)
		{
			ft_putchar(map->map[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
