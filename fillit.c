/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:35:05 by elfetoua          #+#    #+#             */
/*   Updated: 2019/07/16 13:17:14 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage(void)
{
	write(1, "usage: ./fillit target_file\n", 28);
}

void	print(char ***str, int num_tit)
{
	int		i;
	char	**map;
	t_titro	*mine;

	i = 0;
	mine = stock(str, num_tit);
	while (i < num_tit)
	{
		freedoubledem(str[i]);
		i++;
	}
	free(str);
	map = backtracking(mine, num_tit);
	i = 0;
	while (map[i] != NULL)
	{
		ft_putendl(map[i]);
		i++;
	}
	freedoubledem(map);
	freemine(mine, num_tit);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	***str;

	if (argc != 2)
		usage();
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (verification(argv[1]) == 1)
		{
			if (count_titris(argv[1]) > 0)
			{
				str = save(argv[1], count_titris(argv[1]));
				if (cnx_per_bloc(str, count_titris(argv[1])) == 1)
					print(str, count_titris(argv[1]));
				else
					freerror(str, count_titris(argv[1]));
			}
			else
				write(1, "error\n", 6);
		}
		else
			write(1, "error\n", 6);
	}
	return (0);
}

void	freerror(char ***str, int num_tit)
{
	int i;

	i = 0;
	while (i < num_tit)
	{
		freedoubledem(str[i]);
		i++;
	}
	free(str);
	write(1, "error\n", 6);
}
