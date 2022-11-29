/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 02:03:33 by hiantrin          #+#    #+#             */
/*   Updated: 2019/07/16 13:43:49 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_titro		*stock(char ***str, int num_tit)
{
	t_titro	*mine;
	int		i;

	i = 0;
	mine = (t_titro *)malloc(sizeof(t_titro) * num_tit);
	while (i < num_tit)
	{
		mine[i].titris = (t_posi *)malloc(sizeof(t_posi) * 4);
		i++;
	}
	mine = remplir_mine(str, num_tit, mine);
	return (mine);
}

t_titro		*remplir_mine(char ***str, int num_tit, t_titro *mine)
{
	int		i;
	char	c;

	i = 0;
	while (i < num_tit)
	{
		c = character(str[i]);
		mine[i].c = c;
		mine[i].titris = remplir_titris(str[i], mine[i].titris);
		i++;
	}
	return (mine);
}

t_posi		*remplir_titris(char **str, t_posi *titris)
{
	int i;
	int	j;
	int a;
	int	s_i;
	int	s_j;

	s_i = 0;
	s_j = -1;
	a = 0;
	while (a < 4)
	{
		if (a == 0)
		{
			next_position(str, &s_i, &s_j);
			i = s_i;
			j = s_j;
		}
		else
			next_position(str, &i, &j);
		titris[a].x = i - s_i;
		titris[a].y = j - s_j;
		a++;
	}
	return (titris);
}
