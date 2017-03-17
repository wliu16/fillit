/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:02:57 by wliu              #+#    #+#             */
/*   Updated: 2016/12/12 15:04:26 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*str;
	t_lst	*input;

	if (argc == 2)
	{
		str = readfile(argv[1]);
		if (str == NULL || firstcheck(str) == 0)
		{
			error();
			return (0);
		}
		input = create_list(str);
		if (input != NULL)
			ft_fillit(input);
		else
			error();
	}
	else
		usage();
	return (0);
}
