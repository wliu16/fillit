/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:05:21 by wliu              #+#    #+#             */
/*   Updated: 2016/12/12 11:00:45 by sijang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*readfile(char *file)
{
	int		fd;
	char	c;
	char	*res;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	res = ft_strnew(21 * 26);
	i = 0;
	while (read(fd, &c, 1))
	{
		if (c != '.' && c != '#' && c != '\n')
		{
			free(res);
			return (NULL);
		}
		res[i] = c;
		i++;
	}
	return (res);
}

int		firstcheck(char *str)
{
	int	i;
	int	len;
	int	pound;

	i = 0;
	len = 0;
	pound = 0;
	while (str[i])
	{
		if (str[i] == '\n' && i % 21 % 5 != 4 && i % 21 != 20)
			return (0);
		else if (str[i] == '#')
			pound++;
		if (i % 21 == 19)
		{
			if (pound != 4)
				return (0);
			pound = 0;
		}
		i++;
		len++;
	}
	if (len % 21 != 20)
		return (0);
	return (1);
}
