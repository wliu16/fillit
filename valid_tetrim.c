/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:03:19 by wliu              #+#    #+#             */
/*   Updated: 2016/12/12 11:00:54 by sijang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Check valid tetriminos without listing all valid shapes: 
//(1) Choose 2 blocks from 4 => 6 combinations
//(2) Check 6 combinations. If two blocks in a combination are adjacent, counter++
//(3) If counter >= 3 (more specifically 3 or 4) => valid tetriminos
static int		check_coh(int a, int b)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = a / 5;
	x2 = b / 5;
	y1 = a % 5;
	y2 = b % 5;
	if (x1 == x2)
	{
		if (y1 - y2 == 1 || y1 - y2 == -1)
			return (1);//two blocks are adjacent
		else
			return (0);
	}
	else if (y1 == y2)
	{
		if (x1 - x2 == 1 || x1 - x2 == -1)
			return (1);//two blocks are adjacent
		else
			return (0);
	}
	else
		return (0);
}

static int		check_tetrim(int *index)
{
	int i;
	int	j;
	int	coh;

	coh = 0;
	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 4)
		{
			if (check_coh(index[i], index[j]))
				coh++;
			j++;
		}
		i++;
	}
	if (coh < 3)
		return (0);
	return (1);
}

static t_lst	*create_helper(char **str, int hei, int wid)
{
	t_lst	*res;

	res = (t_lst *)malloc(sizeof(t_lst));
	res->shape = str;
	res->hei = hei;
	res->wid = wid;
	res->letter = '0';
	res->next = NULL;
	return (res);
}

static t_lst	*create_tetrim(char **str, int *pound, int x, int y)
{
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;
	char	**res;

	min_x = min(pound[0] / 5, pound[1] / 5, pound[2] / 5, pound[3] / 5);
	min_y = min(pound[0] % 5, pound[1] % 5, pound[2] % 5, pound[3] % 5);
	max_x = max(pound[0] / 5, pound[1] / 5, pound[2] / 5, pound[3] / 5);
	max_y = max(pound[0] % 5, pound[1] % 5, pound[2] % 5, pound[3] % 5);
	res = new_matrix(max_x - min_x + 1, max_y - min_y + 1);
	while (x <= max_x - min_x)
	{
		y = 0;
		while (y <= max_y - min_y)
		{
			res[x][y] = str[min_x + x][min_y + y];
			y++;
		}
		x++;
	}
	free_matrix(str);
	return (create_helper(res, max_x - min_x + 1, max_y - min_y + 1));
}

t_lst			*valid_tetrim(char *str)
{
	char	**mat;
	int		i;
	int		pound[4];
	int		p;

	mat = new_matrix(5, 5);
	i = 0;
	p = 0;
	while (str[i] && i < 20)
	{
		if (str[i] == '#')
			pound[p++] = i;
		if (i % 5 != 4)
			mat[i / 5][i % 5] = str[i];
		i++;
	}
	if (check_tetrim(pound) == 0)
	{
		free_matrix(mat);
		return (NULL);
	}
	i = 0;
	p = 0;
	return (create_tetrim(mat, pound, i, p));
}
