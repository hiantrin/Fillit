/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:13:59 by hiantrin          #+#    #+#             */
/*   Updated: 2019/07/16 12:59:07 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_titris(char *file)
{
	int		i;
	int		fd;
	int		count;
	char	*line;

	i = 0;
	count = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		if (i == 4)
		{
			count++;
			i = -1;
		}
		free(line);
	}
	close(fd);
	if (count > 26)
		return (0);
	return (count);
}

char	**titris(int fd)
{
	char	*line;
	char	**str;
	int		i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * 5);
	str[4] = NULL;
	while (i < 4)
	{
		get_next_line(fd, &line);
		str[i] = line;
		i++;
	}
	if (get_next_line(fd, &line))
		free(line);
	return (str);
}

char	***save(char *file, int num_tit)
{
	char	***str;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	str = (char ***)malloc(sizeof(char **) * num_tit);
	while (i < num_tit)
	{
		str[i] = titris(fd);
		i++;
	}
	close(fd);
	return (alpha_titris(str, num_tit));
}

char	***alpha_titris(char ***str, int num_tit)
{
	int i;
	int j;
	int a;

	a = 0;
	while (a < num_tit)
	{
		i = 0;
		while (str[a][i] != NULL)
		{
			j = 0;
			while (str[a][i][j] != '\0')
			{
				if (str[a][i][j] == '#')
					str[a][i][j] = a + 'A';
				j++;
			}
			i++;
		}
		a++;
	}
	return (str);
}

int		cnx_count(char **str, int i, int j, char c)
{
	int dash_cnx;

	dash_cnx = 0;
	while (str[i] != NULL)
	{
		if (str[i][j] == c)
		{
			if (i == 3 && str[i][j + 1] == c)
				dash_cnx++;
			else if (i != 3)
			{
				if (str[i][j + 1] == c)
					dash_cnx++;
				if (str[i + 1][j] == c)
					dash_cnx++;
			}
		}
		j++;
		if (j == 4)
		{
			i++;
			j = 0;
		}
	}
	return (dash_cnx);
}
