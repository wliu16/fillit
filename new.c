/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:14:53 by wliu              #+#    #+#             */
/*   Updated: 2016/12/12 11:00:30 by sijang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (size + 2));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i <= size + 1)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}

char	**new_matrix(int x, int y)
{
	char	**res;
	int		i;
	int		j;

	res = (char **)malloc(sizeof(char *) * (x + 1));
	i = 0;
	j = 0;
	while (i < x)
	{
		res[i] = ft_strnew(y);
		i++;
	}
	res[i] = 0;
	return (res);
}

t_map	*new_map(int size)
{
	t_map	*newmap;
	char	**str;
	int		x;
	int		y;

	x = -1;
	newmap = (t_map *)malloc(sizeof(t_map));
	str = (char **)malloc(sizeof(char *) * size);
	while (++x < size)
	{
		str[x] = (char *)malloc(sizeof(char) * (size + 2));
		y = -1;
		while (++y < size)
			str[x][y] = PATH;
		str[x][size] = '\n';
		str[x][size + 1] = 0;
	}
	newmap->map = str;
	newmap->size = size;
	newmap->filled = 0;
	return (newmap);
}
