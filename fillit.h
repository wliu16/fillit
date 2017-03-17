/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:00:17 by wliu              #+#    #+#             */
/*   Updated: 2016/12/12 15:36:23 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FALSE 0
# define TRUE 1
# define PATH '.'

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct	s_lst
{
	char			**shape;
	int				wid;
	int				hei;
	char			letter;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_map
{
	char	**map;
	int		size;
	int		filled;
}				t_map;

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

char			*readfile(char *file);
int				firstcheck(char *str);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			error(void);
void			usage(void);
void			printmap(t_map *map);
char			**new_matrix(int x, int y);
t_map			*new_map(int size);
char			*ft_strnew(size_t size);
void			free_matrix(char **matrix);
void			free_map(t_map *map);
void			free_tetrim(t_lst *tetrim);
t_lst			*create_list(char *str);
t_lst			*add_tetrim(t_lst *begin, t_lst *new_tetrim, char c);
t_lst			*valid_tetrim(char *str);
int				min(int a, int b, int c, int d);
int				max(int a, int b, int c, int d);
void			ft_fillit(t_lst *lst);
int				solver(t_lst *lst, t_map *cm, t_pos cur);
void			mapback(t_lst *lb, t_map *mb, t_pos po);
int				ck_promising(t_lst *cb, t_map *cm, int x, int y);
int				ft_fndsquare(int n);
char			*ft_strccpy(char *dst, char *src, char c);
int				ft_strlen(const char *s);
char			*ft_strncpy(char *dst, const char *src, int len);
char			**ft_arrcpy(char **dst, char **src);

#endif
