/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sijang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:54:36 by sijang            #+#    #+#             */
/*   Updated: 2016/12/12 13:46:42 by sijang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fndsquare(int n)
{
	int	i;

	i = 1;
	if (n < 2)
		return (1);
	while (i * i < n)
		i++;
	return (i);
}

char	*ft_strccpy(char *dst, char *src, char c)
{
	while (*src && *src != '\n')
	{
		if (*src != c)
		{
			if (*dst == c)
				*dst = *src;
			else if (*dst != c)
				return (NULL);
		}
		dst++;
		src++;
	}
	return (dst);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dst, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (src[i])
			dst[i] = src[i];
		else
			break ;
		i++;
	}
	while (i < len)
		dst[i++] = '\0';
	return (dst);
}

char	**ft_arrcpy(char **dst, char **src)
{
	if (!src)
		return (dst);
	while (*src)
	{
		ft_strncpy(*dst, *src, ft_strlen(*src) + 1);
		dst++;
		src++;
	}
	return (dst);
}
