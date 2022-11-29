/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 00:53:58 by hiantrin          #+#    #+#             */
/*   Updated: 2019/07/16 14:08:43 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**backtracking(t_titro *mine, int num_tit)
{
	char	**map;
	int		i;

	i = num_tit;
	map = ft_map(i);
	while (cherche_count(map, mine[num_tit - 1].c) != 4)
	{
		map = solve(mine, num_tit, map);
		if (cherche_count(map, mine[num_tit - 1].c) == 4)
			return (map);
		map = final_track(mine, num_tit, map, 0);
		if (cherche_count(map, mine[num_tit - 1].c) == 4)
			return (map);
		i++;
		freedoubledem(map);
		map = ft_map(i);
	}
	return (map);
}

char	**final_track(t_titro *mine, int num_tit, char **map, int j)
{
	while ((cherche_count(map, mine[j].c) == 4))
	{
		if (cherche_count(map, mine[num_tit - 1].c) == 4)
			return (map);
		if ((j + 2) < num_tit)
			map = final_track(mine, num_tit, map, j + 1);
		while (cherche_count(map, mine[j + 1].c) != 4)
		{
			map = move_titris(mine[j], map);
			if (cherche_count(map, mine[j].c) == 4)
				solve(&mine[j + 1], num_tit - (j + 1), map);
			else
				break ;
			if (cherche_count(map, mine[num_tit - 1].c) == 4)
				return (map);
		}
	}
	return (map);
}

char	**move_titris(t_titro mine, char **map)
{
	int a;
	int b;

	a = 0;
	b = 0;
	cherche(map, &a, &b, mine.c);
	map = clean_titris(map, mine.c);
	map = move(mine, map, a, b + 1);
	return (map);
}

char	**move(t_titro mine, char **map, int a, int b)
{
	while (map[a] != NULL)
	{
		while (map[a][b] != '\0')
		{
			if (map[a][b] == '.' && if_can_put(mine.titris, map, a, b) == 1)
				return (put_tit(mine, map, a, b));
			b++;
		}
		a++;
		b = 0;
	}
	return (map);
}

int		cherche_count(char **map, char c)
{
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
