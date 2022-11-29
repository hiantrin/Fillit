/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:35:41 by elfetoua          #+#    #+#             */
/*   Updated: 2019/07/16 14:23:52 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef	struct	s_posi
{
	int	x;
	int	y;
}				t_posi;

typedef struct	s_titro
{
	char		c;
	t_posi		*titris;
}				t_titro;

int				verification(char *file);
void			freedoubledem(char **map);
void			freerror(char ***str, int num_tit);
void			freemine(t_titro *mine, int num_tit);
int				cnx_per_bloc(char ***str, int num_tit);
void			usage(void);
int				check(char **str);
int				dashes_per_bloc(int fd);
int				count_titris(char *file);
char			**titris(int fd);
char			***save(char *file, int num_tit);
char			***alpha_titris(char ***str, int num_tit);
void			print(char ***str, int num_tit);
int				verifi(int fd);
int				cnx_count(char **str, int i, int j, char c);
t_titro			*stock(char ***str, int num_tit);
t_titro			*remplir_mine(char ***str, int num_tit, t_titro *mine);
t_posi			*remplir_titris(char **str, t_posi *titris);
char			character(char **str);
int				next_position(char **str, int *i, int *j);
char			**backtracking(t_titro *mine, int num_tit);
char			**solve(t_titro *mine, int num_tit, char **map);
char			**rem_map(t_titro mine, char **map);
int				if_can_put(t_posi *titris, char **map, int a, int b);
char			**put_tit(t_titro mine, char **map, int a, int b);
char			**ft_map(int num);
int				cherche_count(char **map, char c);
char			**clean_titris(char **map, char a);
int				cherche(char **map, int *a, int *b, char c);
char			**final_track(t_titro *mine, int num_tit, char **map, int j);
char			**move_titris(t_titro mine, char **map);
char			**move(t_titro mine, char **map, int a, int b);

#endif
