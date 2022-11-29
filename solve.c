/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 01:03:46 by hiantrin          #+#    #+#             */
/*   Updated: 2019/07/16 14:22:43 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**solve(t_titro *mine, int num_tit, char **map)
{
	int	i;

	i = 0;
	while (i < num_tit)
	{
		map = rem_map(mine[i], map);
		if (cherche_count(map, mine[i].c) != 4)
			break ;
		i++;
	}
	return (map);
}

char	**rem_map(t_titro mine, char **map)
{
	int a;
	int b;

	a = 0;
	while (map[a] != NULL)
	{
		b = 0;
		while (map[a][b] != '\0')
		{
			if (map[a][b] == '.' && if_can_put(mine.titris, map, a, b) == 1)
				return (put_tit(mine, map, a, b));
			b++;
		}
		a++;
	}
	return (map);
}

int		if_can_put(t_posi *titris, char **map, int a, int b)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map[a + titris[i].x] == NULL)
			return (0);
		if (map[a + titris[i].x][b + titris[i].y] != '.')
			return (0);
		i++;
	}
	return (1);
}

char	**put_tit(t_titro mine, char **map, int a, int b)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[a + mine.titris[i].x][b + mine.titris[i].y] = mine.c;
		i++;
	}
	return (map);
}
