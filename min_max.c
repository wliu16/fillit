/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:49:12 by wliu              #+#    #+#             */
/*   Updated: 2016/12/12 11:16:31 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int			min(int a, int b, int c, int d)
{
	if (a > b)
		swap_int(&a, &b);
	if (a > c)
		swap_int(&a, &c);
	if (a > d)
		swap_int(&a, &d);
	return (a);
}

int			max(int a, int b, int c, int d)
{
	if (a < b)
		swap_int(&a, &b);
	if (a < c)
		swap_int(&a, &c);
	if (a < d)
		swap_int(&a, &d);
	return (a);
}
