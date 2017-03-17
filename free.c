/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:14:46 by wliu              #+#    #+#             */
/*   Updated: 2016/12/12 11:01:04 by sijang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_tetrim(t_lst *tetrim)
{
	t_lst *next;
	t_lst *curr;

	curr = tetrim;
	while (curr)
	{
		next = curr->next;
		free_matrix(curr->shape);
		curr->next = NULL;
		free(tetrim);
		curr = next;
	}
}

void	free_map(t_map *map)
{
	free_matrix(map->map);
	free(map);
}
