/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 01:00:32 by hiantrin          #+#    #+#             */
/*   Updated: 2019/07/16 12:58:56 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_map(int num)
{
	char	**str;
	int		i;
	int		j;

	i = 1;
	while ((num * 4) > (i * i))
		i++;
	str = (char **)malloc(sizeof(char *) * (i + 1));
	str[i] = NULL;
	num = i;
	i = 0;
	while (i < num)
	{
		str[i] = malloc(sizeof(char) * (num + 1));
		str[i][num] = '\0';
		j = 0;
		while (j < num)
		{
			str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (str);
}

int		next_position(char **str, int *i, int *j)
{
	(*j)++;
	while (str[*i] != NULL)
	{
		while (str[*i][*j] != '\0')
		{
			if (str[*i][*j] >= 'A' && str[*i][*j] <= 'Z')
				return (0);
			(*j)++;
		}
		(*i)++;
		*j = 0;
	}
	return (0);
}

char	**clean_titris(char **map, char a)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == a)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

char	character(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				return (str[i][j]);
			j++;
		}
		i++;
	}
	return ('.');
}

int		cherche(char **map, int *a, int *b, char c)
{
	while (map[*a][*b] != c)
	{
		if (map[*a][*b] == '\0')
		{
			(*a)++;
			*b = 0;
		}
		if (map[*a] == NULL)
			return (0);
		if (map[*a][*b] != c)
			(*b)++;
		else
			break ;
	}
	return (1);
}
