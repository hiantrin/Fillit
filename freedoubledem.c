/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedoubledem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:05:20 by elfetoua          #+#    #+#             */
/*   Updated: 2019/07/16 18:59:24 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	freedoubledem(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	freemine(t_titro *mine, int num_tit)
{
	int i;

	i = 0;
	while (i < num_tit)
	{
		free(mine[i].titris);
		i++;
	}
	free(mine);
}
