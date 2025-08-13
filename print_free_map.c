/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_free_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:51:27 by jculleto          #+#    #+#             */
/*   Updated: 2025/08/13 17:19:48 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->grid[i])
		{
			write(1, map->grid[i], map->cols);
			write(1, "\n", 1);
		}
		i++;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map->grid)
	{
		return ;
	}
	while (i < map->rows)
	{
		if (map->grid[i])
		{
			free(map->grid[i]);
			map->grid[i] = NULL;
		}
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}
